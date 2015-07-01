#ifndef __ANDROID_HELPER_H__
#define __ANDROID_HELPER_H__

#include <string>

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include "../cocos2d/cocos/platform/android/jni/JniHelper.h"

#else

typedef class _jobject {} *jobject;

typedef class _jstring : public _jobject {} *jstring;

#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

namespace android
{
	inline jstring NewStringUTF(const char* pUTF)
	{
		USING_NS_CC;
		jstring jReturn(nullptr);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JNIEnv* pJNIEnv = JniHelper::getEnv();
		if (pJNIEnv)
		{
			jReturn = pJNIEnv->NewStringUTF(pUTF);
		}
#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		return jReturn;
	}

	inline void CallStaticVoidMethod(const char* className, const char* methodName, const char* paramCode, ...)
	{
		USING_NS_CC;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo MethodInfo = { 0 };
		if (JniHelper::getStaticMethodInfo(MethodInfo, className, methodName, paramCode))
		{
			va_list args;
			va_start(args, paramCode);
			MethodInfo.env->CallStaticVoidMethodV(MethodInfo.classID, MethodInfo.methodID, args);
			va_end(args);
		}
#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	}

	inline bool CallStaticBoolMethod(const char* className, const char* methodName, const char* paramCode, ...)
	{
		USING_NS_CC;
		bool bReturn(false);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo MethodInfo = { 0 };
		if (JniHelper::getStaticMethodInfo(MethodInfo, className, methodName, paramCode))
		{
			va_list args;
			va_start(args, paramCode);
			bReturn = MethodInfo.env->CallStaticBooleanMethodV(MethodInfo.classID, MethodInfo.methodID, args)? true:false;
			va_end(args);
		}
#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		return bReturn;
	}

	inline int CallStaticIntMethod(const char* className, const char* methodName, const char* paramCode, ...)
	{
		USING_NS_CC;
		int nReturn(0);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo MethodInfo = { 0 };
		if (JniHelper::getStaticMethodInfo(MethodInfo, className, methodName, paramCode))
		{
			va_list args;
			va_start(args, paramCode);
			nReturn = MethodInfo.env->CallStaticIntMethodV(MethodInfo.classID, MethodInfo.methodID, args);
			va_end(args);
		}
#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		return nReturn;
	}

	inline std::string CallStaticStringMethod(const char* className, const char* methodName, const char* paramCode, ...)
	{
		USING_NS_CC;
		std::string strReturn;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo MethodInfo = { 0 };
		if (JniHelper::getStaticMethodInfo(MethodInfo, className, methodName, paramCode))
		{
			va_list args;
			va_start(args, paramCode);
			jstring str = (jstring)MethodInfo.env->CallStaticObjectMethodV(MethodInfo.classID, MethodInfo.methodID, args);
			va_end(args);
			const char* pszUTF = MethodInfo.env->GetStringUTFChars(str, nullptr);
			strReturn = pszUTF;
			MethodInfo.env->ReleaseStringUTFChars(str, pszUTF);
		}
#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		return strReturn;
	}

	inline jobject CallStaticObjectMethod(const char* className, const char* methodName, const char* paramCode, ...)
	{
		USING_NS_CC;
		jobject objReturn(nullptr);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo MethodInfo = { 0 };
		if (JniHelper::getStaticMethodInfo(MethodInfo, className, methodName, paramCode))
		{
			va_list args;
			va_start(args, paramCode);
			objReturn = MethodInfo.env->CallStaticObjectMethodV(MethodInfo.classID, MethodInfo.methodID, args);
			va_end(args);
		}
#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		return objReturn;
	}

	inline void CallVoidMethod(jobject obj, const char* className, const char* methodName, const char* paramCode, ...)
	{
		USING_NS_CC;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo MethodInfo = { 0 };
		if (JniHelper::getMethodInfo(MethodInfo, className, methodName, paramCode))
		{
			va_list args;
			va_start(args, paramCode);
			MethodInfo.env->CallVoidMethodV(obj, MethodInfo.methodID, args);
			va_end(args);
		}
#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	}

	inline bool CallBoolMethod(jobject obj, const char* className, const char* methodName, const char* paramCode, ...)
	{
		USING_NS_CC;
		bool bReturn(false);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo MethodInfo = { 0 };
		if (JniHelper::getMethodInfo(MethodInfo, className, methodName, paramCode))
		{
			va_list args;
			va_start(args, paramCode);
			bReturn = MethodInfo.env->CallBooleanMethodV(obj, MethodInfo.methodID, args)? true:false;
			va_end(args);
		}
#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		return bReturn;
	}

	inline int CallIntMethod(jobject obj, const char* className, const char* methodName, const char* paramCode, ...)
	{
		USING_NS_CC;
		int nReturn(0);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo MethodInfo = { 0 };
		if (JniHelper::getMethodInfo(MethodInfo, className, methodName, paramCode))
		{
			va_list args;
			va_start(args, paramCode);
			nReturn = MethodInfo.env->CallIntMethodV(obj, MethodInfo.methodID, args);
			va_end(args);
		}
#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		return nReturn;
	}

	inline std::string CallStringMethod(jobject obj, const char* className, const char* methodName, const char* paramCode, ...)
	{
		USING_NS_CC;
		std::string strReturn;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo MethodInfo = { 0 };
		if (JniHelper::getMethodInfo(MethodInfo, className, methodName, paramCode))
		{
			va_list args;
			va_start(args, paramCode);
			jstring str = (jstring)MethodInfo.env->CallObjectMethodV(obj, MethodInfo.methodID, args);
			va_end(args);
			const char* pszUTF = MethodInfo.env->GetStringUTFChars(str, nullptr);
			strReturn = pszUTF;
			MethodInfo.env->ReleaseStringUTFChars(str, pszUTF);
		}
#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		return strReturn;
	}

	inline jobject CallObjectMethod(jobject obj, const char* className, const char* methodName, const char* paramCode, ...)
	{
		USING_NS_CC;
		jobject objReturn(nullptr);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo MethodInfo = { 0 };
		if (JniHelper::getMethodInfo(MethodInfo, className, methodName, paramCode))
		{
			va_list args;
			va_start(args, paramCode);
			objReturn = MethodInfo.env->CallObjectMethodV(obj, MethodInfo.methodID, args);
			va_end(args);
		}
#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		return objReturn;
	}
}

#endif // __ANDROID_HELPER_H__

