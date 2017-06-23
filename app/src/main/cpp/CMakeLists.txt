

cmake_minimum_required(VERSION 3.4.1)


set(PWD ${CMAKE_CURRENT_SOURCE_DIR})
set(LIB_DIR ${PWD}/../jniLibs/${ANDROID_ABI})

include_directories(${PWD}/include)

add_library(native-lib SHARED native-lib.cpp)


find_library(log-lib log )



target_link_libraries(native-lib ${log-lib} )