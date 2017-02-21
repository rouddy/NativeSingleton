
#include <string.h>
#include "singleton.h"
#include <android/log.h>

#define  LOG_TAG    "NDK_TEST"
#define  ALOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

JNIEXPORT jobject Java_com_rouddy_nativesingleton_NativeSingleton_getSingleton(JNIEnv* env, jclass clazz, jobject clsObject)
{
	return Singleton::getSingleton(clazz);
}

JNIEXPORT void Java_com_rouddy_nativesingleton_NativeSingleton_setSingleton(JNIEnv* env, jclass clazz, jobject clsObject, jobject object)
{
	jobject globalObj = env->NewGlobalRef(object);

	Singleton::setSingleton(clazz, globalObj);
}

std::map<jobject, jobject> Singleton::instanceMap;

jobject Singleton::getSingleton(jobject clsObject)
{
	auto iter = instanceMap.find(clsObject);
	if (iter == instanceMap.end()) {
		return NULL;
	}

	return instanceMap[clsObject];
}

void Singleton::setSingleton(jobject clsObject, jobject object)
{
	instanceMap[clsObject] = object;
}
