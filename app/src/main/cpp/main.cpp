//
// Created by fanzhengchen on 6/4/17.
//
#include <jni.h>
#include <android/log.h>
#include <uv.h>
#include <openssl/rand.h>

uv_loop_t* uv_loop;
extern "C"
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {

    uv_loop = uv_default_loop();

    long  a = random();

    __android_log_print(ANDROID_LOG_ERROR, "main", "%s %d", "in", a);

    return JNI_VERSION_1_6;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_fzc_jni_Native_onLoad(JNIEnv *env, jclass type) {

    // TODO


    return env->NewStringUTF("onload");
}