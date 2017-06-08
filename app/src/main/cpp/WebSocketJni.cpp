//
// Created by fanzhengchen on 6/4/17.
//
#include <jni.h>
#include <android/log.h>
#include <uv.h>
#include <openssl/rand.h>
#include "HTTPSocket.h"
#include "uWS.h"
#include <android/log.h>
#include <string>
#include "Socket.h"

void log(const char *fmt, ...) {
    va_list args;
    va_start(args,fmt);
    __android_log_print(ANDROID_LOG_DEBUG, "WebSocketClient", fmt, args);
    va_end(args);
}



class WebSocketClientManager {
private:
    uWS::WebSocket<uWS::CLIENT> *webSocketClient;
    uWS::Hub hub;
    std::string mUri;



public:

    ~WebSocketClientManager() {
    }

    void
    connect(const char *uri) {
        this->mUri = std::string(uri);

        hub.onConnection([](uWS::WebSocket<uWS::CLIENT> *ws, uWS::HttpRequest req) {
            uS::Socket::Address address = ws->getAddress();
            log("%s %s %d", address.address, address.family, address.port);
        });

        hub.connect(this->mUri, nullptr);

        hub.run();
    }

} *pWebSocketClientManager = nullptr;

extern "C"
JNIEXPORT void JNICALL
Java_com_fzc_jni_WebSocketClient_connec(JNIEnv *env, jobject instance, jstring uri_) {
    jboolean iscopy = 0x1;
    const char *uri = env->GetStringUTFChars(uri_, 0);
    pWebSocketClientManager->connect(uri);
//    env->ReleaseStringUTFChars(uri_, uri);
}

extern "C"
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    pWebSocketClientManager = new WebSocketClientManager();
    return JNI_VERSION_1_6;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_fzc_jni_Native_onLoad(JNIEnv *env, jclass type) {

    delete (pWebSocketClientManager);
    return env->NewStringUTF("onload");
}