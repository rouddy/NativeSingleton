
#include <string.h>
#include "singleton.h"
#include <android/log.h>

#define  LOG_TAG    "NDK_TEST"
#define  ALOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

JNIEXPORT jobject Java_com_rouddy_nativesingleton_NativeSingleton_getSingleton(JNIEnv* env, jclass clazz, jstring clsName)
{
	const char *chName = env->GetStringUTFChars(clsName, 0);
	std::string strName(chName);
	env->ReleaseStringUTFChars(clsName, chName);
	return Singleton::getSingleton(strName);
}

JNIEXPORT void Java_com_rouddy_nativesingleton_NativeSingleton_setSingleton(JNIEnv* env, jclass clazz, jstring clsName, jobject object)
{
	const char *chName = env->GetStringUTFChars(clsName, 0);
	std::string strName(chName);
	env->ReleaseStringUTFChars(clsName, chName);
	jobject globalObj = env->NewGlobalRef(object);

	Singleton::setSingleton(strName, globalObj);
}

std::map<std::string, jobject> Singleton::instanceMap;

jobject Singleton::getSingleton(std::string clsName)
{
	auto iter = instanceMap.find(clsName);
	if (iter == instanceMap.end())
	{
		return NULL;
	}

	return instanceMap[clsName];
}

void Singleton::setSingleton(std::string clsName, jobject object)
{
	instanceMap[clsName] = object;
}
