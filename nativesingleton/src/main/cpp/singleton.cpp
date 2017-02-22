
#include <string.h>
#include "singleton.h"
#include <android/log.h>

#define  LOG_TAG    "NDK_TEST"
#define  ALOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

std::string jstringToString(JNIEnv* env, jstring jstr)
{
	const char *charStr = env->GetStringUTFChars(jstr, 0);
	std::string str = std::string(charStr);
	env->ReleaseStringUTFChars(jstr, charStr);
	return str;
}

JNIEXPORT jobject Java_com_rouddy_nativesingleton_NativeSingleton_getSingleton(JNIEnv* env, jclass clazz, jstring clsName)
{
	std::string strClsName = jstringToString(env, clsName);
	return Singleton::getSingleton(strClsName);
}

JNIEXPORT void Java_com_rouddy_nativesingleton_NativeSingleton_setSingleton(JNIEnv* env, jclass clazz, jstring clsName, jobject object)
{
	std::string strClsName = jstringToString(env, clsName);
	jobject globalObj = env->NewGlobalRef(object);

	Singleton::setSingleton(strClsName, globalObj);
}

std::map<std::string, jobject> Singleton::instanceMap;

jobject Singleton::getSingleton(std::string clsName)
{
	auto iter = instanceMap.find(clsName);
	if (iter == instanceMap.end()) {
		return NULL;
	}

	return instanceMap[clsName];
}

void Singleton::setSingleton(std::string clsName, jobject object)
{
	instanceMap[clsName] = object;
}
