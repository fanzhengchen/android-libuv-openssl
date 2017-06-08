//
// Created by fanzhengchen on 6/4/17.
//
#include <jni.h>
#include <android/log.h>
#include "libwebsockets.h"
#include <sys/time.h>
#include <signal.h>


typedef struct WebSocketClient{

    lws_context_creation_info *pCreateInfo;
    lws_client_connect_info *pConnectInfo;
    lws_context *pClient;

    WebSocketClient(){
        pCreateInfo = (lws_context_creation_info *)malloc(sizeof(lws_context_creation_info));
        pConnectInfo = (lws_client_connect_info *)malloc(sizeof(lws_client_connect_info));
        pClient = (lws_context *)malloc(sizeof(lws_context));
    }

    void init(){
        pConnectInfo->protocol="ws";
        pConnectInfo->port=20000;
        pConnectInfo->address="172.16.14.15";
        pConnectInfo->host="172.16.14.15";
        pConnectInfo->path="webSocket";


        pClient = lws_create_context(pCreateInfo);

    }

    void connect(){
//        lws_client_connect();
    }
    ~WebSocketClient(){
        free(pClient);
        free(pConnectInfo);
        free(pClient);
    }

}WebSocketClient;
static WebSocketClient client;


extern "C"
JNIEXPORT void JNICALL
Java_com_fzc_jni_WebSocketClient_connec(JNIEnv *env, jobject instance, jstring uri_) {
    const char *uri = env->GetStringUTFChars(uri_, 0);
    env->ReleaseStringUTFChars(uri_, uri);
}

extern "C"
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {

    return JNI_VERSION_1_6;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_fzc_jni_Native_onLoad(JNIEnv *env, jclass type) {

    return env->NewStringUTF("onload");
}