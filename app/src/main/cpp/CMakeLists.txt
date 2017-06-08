
cmake_minimum_required(VERSION 3.4.1)

set(lib_dir ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(uv STATIC IMPORTED)
set_target_properties(uv PROPERTIES IMPORTED_LOCATION ${lib_dir}/libuv.a)


add_library(crypto STATIC IMPORTED)
set_target_properties(crypto PROPERTIES IMPORTED_LOCATION ${lib_dir}/libcrypto.a)

add_library(ssl STATIC IMPORTED)
set_target_properties(ssl PROPERTIES IMPORTED_LOCATION ${lib_dir}/libssl.a)


add_library(lws
            STATIC
            IMPORTED)
set_target_properties(lws PROPERTIES IMPORTED_LOCATION ${lib_dir}/libwebsockets.a)



add_library(WebSocketJni SHARED WebSocketJni.cpp)
target_link_libraries( WebSocketJni
                       lws
                       log )
