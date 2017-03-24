//
// Created by fanzhengchen on 3/24/17.
//

#include <string>
#include "jni.h"
#include "android/log.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_fzc_jni_JniClass_getStringFromJni(JNIEnv *env, jobject instance) {
    std::string str = "jni class practice";
    return env->NewStringUTF(str.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_fzc_jni_JniClass_getJavaClass(JNIEnv *env, jobject instance) {

    // TODO
    jclass jclazz = env->FindClass("com/fzc/jni/JniClass");
    __android_log_print(ANDROID_LOG_DEBUG, "get java class", "%d", jclazz != nullptr);
    jmethodID method = env->GetMethodID(jclazz, "printString", "(Ljava/lang/String;)V");

    jobject obj = env->NewObject(jclazz, method);


    __android_log_print(ANDROID_LOG_DEBUG, "get java method", "%d", method != nullptr);

    env->CallVoidMethod(obj, method, "a call from cpp");
}

