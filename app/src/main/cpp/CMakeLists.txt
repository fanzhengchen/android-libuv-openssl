

cmake_minimum_required(VERSION 3.4.1)


set(PWD ${CMAKE_CURRENT_SOURCE_DIR})
set(LIB_DIR ${PWD}/../jniLibs/${ANDROID_ABI})

add_library(ssl STATIC IMPORTED)
add_library(crypto STATIC IMPORTED)
add_library(uv STATIC IMPORTED)
add_library(lws SHARED IMPORTED)

set_target_properties(ssl PROPERTIES IMPORTED_LOCATION ${LIB_DIR}/libssl.a)
set_target_properties(crypto PROPERTIES IMPORTED_LOCATION ${LIB_DIR}/libcrypto.a)
set_target_properties(uv PROPERTIES IMPORTED_LOCATION ${LIB_DIR}/libuv.a)
set_target_properties(lws PROPERTIES IMPORTED_LOCATION ${LIB_DIR}/libwebsockets.so)

include_directories(${PWD}/include)

add_library(native-lib SHARED native-lib.cpp)

find_library(log-lib log )

target_link_libraries(native-lib ${log-lib} )

add_library(ws SHARED WebSocket.h WebSocket.cpp)

target_link_libraries(ws ssl crypto lws uv log)
