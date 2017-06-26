//
// Created by fanzhengchen on 6/23/17.
//

#include "WebSocket.h"
#include "XgnLog.h"

const int BUFFER_SIZE = 1 << 12;

static lws_context_creation_info creation_info;
static lws_client_connect_info connect_info;
static lws_context *context;
static JavaVM *gJvm = nullptr;
static JNIEnv *gEnv = nullptr;
static lws *wsi = nullptr;
static u_int8_t buffer[BUFFER_SIZE];

static volatile int force_exit = 0;

/**
 * session data , it could be tranfered to the event with lws_callback_reasons
 */
struct per_session_data {
    const unsigned char *data;
};

enum websocket_protocols {
    PROTOCOL_DUMP_INCREMENT = 0,
    PROTOCOL_COUNT
};

const lws_protocols protocols[] = {
        {"dump-increment-protocol", callback, sizeof(per_session_data), BUFFER_SIZE},
        {NULL, NULL,                          0,                        0}
};

const lws_extension exts[] = {
        {"deflate-frame", lws_extension_callback_pm_deflate, "deflate-frame"},
        {NULL, NULL, NULL}
};

/*
 * Class:     com_xgn_WebSocket
 * Method:    init
 * Signature: ()V
 */
extern "C"
JNIEXPORT void JNICALL Java_com_xgn_WebSocket_init
        (JNIEnv *env, jobject obj) {
    jni_xgn_WebSocket_init(env, obj);
};

/*
 * Class:     com_xgn_WebSocket
 * Method:    connect
 * Signature: ()V
 */
extern "C"
JNIEXPORT void JNICALL Java_com_xgn_WebSocket_connect
        (JNIEnv *env, jobject obj) {
    jni_xgn_WebSocket_connect(env, obj);
};

/*
 * Class:     com_xgn_WebSocket
 * Method:    send
 * Signature: (Ljava/lang/String;)V
 */
extern "C"
JNIEXPORT void JNICALL Java_com_xgn_WebSocket_send
        (JNIEnv *env, jobject _jobject, jstring _jstring) {
    jni_xgn_WebSocket_send(env, _jobject, _jstring);
};

/*
 * Class:     com_xgn_WebSocket
 * Method:    sendData
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_com_xgn_WebSocket_sendData
        (JNIEnv *env, jobject _jobject, jbyteArray _jbyteArray) {
    jni_xgn_WebSocket_sendData(env, _jobject, _jbyteArray);
}
/*
 * Class:     com_xgn_WebSocket
 * Method:    close
 * Signature: ()V
 */
extern "C"
JNIEXPORT void JNICALL Java_com_xgn_WebSocket_close
        (JNIEnv *env, jobject _jobject) {
    jni_xgn_WebSocket_close(env, _jobject);
};

static int
callback(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len) {
    switch (reason) {
        case LWS_CALLBACK_CLIENT_ESTABLISHED: {
            LOGV("client established", __LINE__);
            break;
        };
        case LWS_CALLBACK_CLIENT_WRITEABLE: {
            per_session_data *data = (per_session_data *) user;
            LOGV("client writable %s", data->data);
            break;
        };
        case LWS_CALLBACK_CLIENT_RECEIVE_PONG: {
            LOGV("receive pong", __LINE__);
            break;
        };
        case LWS_CALLBACK_CLOSED: {
            LOGV("socket close", __LINE__);
            break;
        };
        case LWS_CALLBACK_GET_THREAD_ID: {
            break;
        }
        case LWS_CALLBACK_WSI_DESTROY: {
            LOGV("disconnected");
            force_exit = 1;
            break;
        };
        case LWS_CALLBACK_CLIENT_RECEIVE: {

        }
        default: {

        }

    }
    return 0;
}

void jni_xgn_WebSocket_init(JNIEnv *env, jobject obj) {
    LOGV("init");
    memset(&creation_info, 0, sizeof(lws_context_creation_info));
    memset(&connect_info, 0, sizeof(lws_client_connect_info));
    force_exit = 0;

    creation_info.port = CONTEXT_PORT_NO_LISTEN;
    creation_info.extensions = exts;
    creation_info.protocols = protocols;
    creation_info.ws_ping_pong_interval = 8;
    creation_info.gid = -1;
    creation_info.uid = -1;

    context = lws_create_context(&creation_info);

    connect_info.address = connect_info.origin = connect_info.host = "172.16.14.115";
    connect_info.port = 20000;
    connect_info.path = "/webSocket";
    connect_info.ssl_connection = 0;
    connect_info.client_exts = exts;
    connect_info.ietf_version_or_minus_one = -1;
    connect_info.protocol = protocols[PROTOCOL_DUMP_INCREMENT].name;
    connect_info.context = context;

}

void jni_xgn_WebSocket_connect(JNIEnv *env, jobject obj) {
    LOGV("connect");
    wsi = lws_client_connect_via_info(&connect_info);

    if (wsi) {
        LOGV("websocket connected");
    } else {
        LOGV("websocket failed to connect");
    }

    while (!force_exit) {
        if (context) {
            lws_service(context, 0);
        } else {
            force_exit = 1;
        }
    }
    wsi = nullptr;
    force_exit = 1;
    lws_context_destroy(context);
    LOGV("exit");
};

void jni_xgn_WebSocket_send(JNIEnv *env, jobject obj, jstring str) {
    LOGV("send message");
    if (wsi) {
        const char *content = env->GetStringUTFChars(str, NULL);
        size_t len = env->GetStringUTFLength(str);

        per_session_data *data = (per_session_data *) lws_get_protocol(wsi)->user;
        LOGV("data is %s :[] send message is:%s", data == nullptr ? "null" : "not null", content);
        lws_write(wsi, (unsigned char *) content, len, LWS_WRITE_TEXT);

        env->ReleaseStringUTFChars(str, content);
    }
};

void jni_xgn_WebSocket_sendData(JNIEnv *env, jobject _jobject, jbyteArray _jbyteArray) {
    LOGV("send binary data");
    if (wsi) {
        jbyte *content = env->GetByteArrayElements(_jbyteArray, NULL);
        size_t len = env->GetArrayLength(_jbyteArray);

        per_session_data *data = (per_session_data *) lws_get_protocol(wsi)->user;
        LOGV("data is %s :[] send message is:%s", data == nullptr ? "null" : "not null", content);
        lws_write(wsi, (unsigned char *) content, len, LWS_WRITE_BINARY);

        env->ReleaseByteArrayElements(_jbyteArray, content, 0);
    }
}

void jni_xgn_WebSocket_close(JNIEnv *env, jobject obj) {
    LOGV("close");
    force_exit = 1;
    if (context) {
//        lws_context_destroy(context);
    }
};

JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    gJvm = vm;

    if (vm->GetEnv((void **) &gEnv, JNI_VERSION_1_6) ^ JNI_OK) {
        return -1;
    }

    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
//     LOGI("JNI_OnUnload");
}
