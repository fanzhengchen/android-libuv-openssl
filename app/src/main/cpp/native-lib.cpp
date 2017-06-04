#include <jni.h>
#include <string>
#include <uv.h>
#include <android/log.h>



extern "C"
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {

//    loop = uv_default_loop();

    __android_log_print(ANDROID_LOG_ERROR, "jni on onload", "%s", "in");

    return JNI_VERSION_1_6;
}

extern "C"
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {

//    uv_loop_close(uv_default_loop());
    __android_log_print(ANDROID_LOG_ERROR, "jni on unload", "%s", "exit a");
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_fzc_jni_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    __android_log_print(ANDROID_LOG_ERROR, "jni on unload", "%s", "exit");
    return env->NewStringUTF(hello.c_str());
}
