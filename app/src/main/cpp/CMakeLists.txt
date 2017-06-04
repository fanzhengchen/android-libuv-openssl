
cmake_minimum_required(VERSION 3.4.1)

add_library(
             native-lib

             SHARED

             native-lib.cpp )


find_library(
              log-lib
              log )



set(lib_dir ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(uv-lib STATIC IMPORTED)
set_target_properties(uv-lib PROPERTIES IMPORTED_LOCATION ${lib_dir}/libuv.a)


add_library(crypto-lib STATIC IMPORTED)
set_target_properties(crypto-lib PROPERTIES IMPORTED_LOCATION ${lib_dir}/libcrypto.a)

add_library(ssl-lib STATIC IMPORTED)
set_target_properties(ssl-lib PROPERTIES IMPORTED_LOCATION ${lib_dir}/libssl.a)

target_link_libraries( # Specifies the target library.
                       native-lib

                       ${log-lib} )

add_library(main SHARED main.cpp)
target_link_libraries( # Specifies the target library.
                       main
                       uv-lib
                       crypto-lib
                       ssl-lib
                       ${log-lib} )
