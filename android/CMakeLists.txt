cmake_minimum_required(VERSION 3.4.1)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 11)

# Specifies a path to native header files.
include_directories(
            ../cpp
            ../node_modules/react-native/React
            ../node_modules/react-native/React/Base
            ../node_modules/react-native/ReactCommon/jsi
)

add_library(fibonachos
            SHARED
            ../node_modules/react-native/ReactCommon/jsi/jsi/jsi.cpp
            ../cpp/react-native-fibonachos.cpp
            ../cpp/react-native-fibonachos.h
            cpp-adapter.cpp
)

target_link_libraries(fibonachos)
