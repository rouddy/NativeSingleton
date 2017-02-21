
#include <jni.h>
#include <string>
#include <map>

/* Header for class HelloNative */
#ifndef NATIVE_SINGLETON_H
#define NATIVE_SINGLETON_H

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jobject Java_com_rouddy_nativesingleton_NativeSingleton_getSingleton(JNIEnv* env, jclass clazz, jobject clsObject);

JNIEXPORT void Java_com_rouddy_nativesingleton_NativeSingleton_setSingleton(JNIEnv* env, jclass clazz, jobject clsObject, jobject object);

#ifdef __cplusplus
}
#endif

class Singleton {
private:
	static std::map<jobject, jobject> instanceMap;

public:
	static jobject getSingleton(jobject clsObject);
	static void setSingleton(jobject clsObject, jobject object);
};

#endif
