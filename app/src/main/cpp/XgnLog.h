//
// Created by mark on 6/26/17.
//

#ifndef ANDROID_LIBUV_OPENSSL_XGN_H
#define ANDROID_LIBUV_OPENSSL_XGN_H

#include "android/log.h"
#include "cstdio"

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT __FILE__ ":" TOSTRING(__LINE__)

#define _STR(x) #x
#define STR(x) _STR(x)
#define TAG __FILE__ ":" STR(__LINE__)

#define LOGV(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, ##__VA_ARGS__)

#endif //ANDROID_LIBUV_OPENSSL_XGN_H