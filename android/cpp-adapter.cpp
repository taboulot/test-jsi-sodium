#include <jni.h>
#include "react-native-fibonachos.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_fibonachos_FibonachosModule_initialize(JNIEnv *env, jclass type, jlong jsiPtr) {
    installFibo(*reinterpret_cast<facebook::jsi::Runtime *>(jsiPtr));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_fibonachos_FibonachosModule_destroy(JNIEnv *env, jclass type) {
    cleanUpFibo();
}
