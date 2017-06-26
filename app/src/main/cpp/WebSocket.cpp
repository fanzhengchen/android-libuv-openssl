//
// Created by fanzhengchen on 6/23/17.
//

#include "WebSocket.h"
#include "XgnLog.h"

void jni_xgn_WebSocket_init(JNIEnv *, jobject);

void jni_xgn_WebSocket_connect(JNIEnv *, jobject);

void jni_xgn_WebSocket_send(JNIEnv *, jobject, jstring);

void jni_xgn_WebSocket_close(JNIEnv *, jobject);
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
 * Method:    close
 * Signature: ()V
 */
extern "C"
JNIEXPORT void JNICALL Java_com_xgn_WebSocket_close
        (JNIEnv *env, jobject _jobject) {
    jni_xgn_WebSocket_close(env, _jobject);
};

void jni_xgn_WebSocket_init(JNIEnv *env, jobject obj) {
    LOGV(__FUNCTION__);
}

void jni_xgn_WebSocket_connect(JNIEnv *env, jobject obj) {
    LOGV(__FUNCTION__);
};

void jni_xgn_WebSocket_send(JNIEnv *env, jobject obj, jstring str) {
    LOGV(__FUNCTION__);
};

void jni_xgn_WebSocket_close(JNIEnv *env, jobject obj) {
    LOGV(__FUNCTION__);
};