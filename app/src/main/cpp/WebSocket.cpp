//
// Created by fanzhengchen on 6/23/17.
//

#include "WebSocket.h"

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
        (JNIEnv *, jobject) {

};

/*
 * Class:     com_xgn_WebSocket
 * Method:    connect
 * Signature: ()V
 */
extern "C"
JNIEXPORT void JNICALL Java_com_xgn_WebSocket_connect
        (JNIEnv *, jobject) {

};

/*
 * Class:     com_xgn_WebSocket
 * Method:    send
 * Signature: (Ljava/lang/String;)V
 */
extern "C"
JNIEXPORT void JNICALL Java_com_xgn_WebSocket_send
        (JNIEnv *, jobject, jstring) {

};

/*
 * Class:     com_xgn_WebSocket
 * Method:    close
 * Signature: ()V
 */
extern "C"
JNIEXPORT void JNICALL Java_com_xgn_WebSocket_close
        (JNIEnv *, jobject) {

};

void jni_xgn_WebSocket_init(JNIEnv *env, jobject obj){

}

void jni_xgn_WebSocket_connect(JNIEnv *env, jobject obj){

};

void jni_xgn_WebSocket_send(JNIEnv *env, jobject obj, jstring str){

};

void jni_xgn_WebSocket_close(JNIEnv *env, jobject obj){

};