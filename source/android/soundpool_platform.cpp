/*
 * android-specific implementation of the soundpool extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "soundpool_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_sound_pool__init;
static jmethodID g_sound_pool__load;
static jmethodID g_sound_pool__play;
static jmethodID g_sound_pool__pause;
static jmethodID g_sound_pool__resume;
static jmethodID g_sound_pool__set_looping;
static jmethodID g_sound_pool__stop;
static jmethodID g_sound_pool__unload;
static jmethodID g_sound_pool__release;

s3eResult soundpoolInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("soundpool");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_sound_pool__init = env->GetMethodID(cls, "sound_pool__init", "(I)V");
    if (!g_sound_pool__init)
        goto fail;

    g_sound_pool__load = env->GetMethodID(cls, "sound_pool__load", "(Ljava/lang/String;I)I");
    if (!g_sound_pool__load)
        goto fail;

    g_sound_pool__play = env->GetMethodID(cls, "sound_pool__play", "(IFFIIF)I");
    if (!g_sound_pool__play)
        goto fail;

    g_sound_pool__pause = env->GetMethodID(cls, "sound_pool__pause", "(I)V");
    if (!g_sound_pool__pause)
        goto fail;

    g_sound_pool__resume = env->GetMethodID(cls, "sound_pool__resume", "(I)V");
    if (!g_sound_pool__resume)
        goto fail;

    g_sound_pool__set_looping = env->GetMethodID(cls, "sound_pool__set_looping", "(II)V");
    if (!g_sound_pool__set_looping)
        goto fail;

    g_sound_pool__stop = env->GetMethodID(cls, "sound_pool__stop", "(I)V");
    if (!g_sound_pool__stop)
        goto fail;

    g_sound_pool__unload = env->GetMethodID(cls, "sound_pool__unload", "(I)V");
    if (!g_sound_pool__unload)
        goto fail;

    g_sound_pool__release = env->GetMethodID(cls, "sound_pool__release", "()V");
    if (!g_sound_pool__release)
        goto fail;



    IwTrace(SOUNDPOOL, ("SOUNDPOOL init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(soundpool, ("One or more java methods could not be found"));
    }

    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);
    return S3E_RESULT_ERROR;

}

void soundpoolTerminate_platform()
{ 
    // Add any platform-specific termination code here
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->DeleteGlobalRef(g_Obj);
    g_Obj = NULL;
}

void sound_pool__init_platform(int maxStreams)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_sound_pool__init, maxStreams);
}

int sound_pool__load_platform(const char* path, int priority)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring path_jstr = env->NewStringUTF(path);
    return (int)env->CallIntMethod(g_Obj, g_sound_pool__load, path_jstr, priority);
}

int sound_pool__play_platform(int soundID, float leftVolume, float rightVolume, int priority, int loop, float rate)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (int)env->CallIntMethod(g_Obj, g_sound_pool__play, soundID, leftVolume, rightVolume, priority, loop, rate);
}

void sound_pool__pause_platform(int streamID)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_sound_pool__pause, streamID);
}

void sound_pool__resume_platform(int streamID)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_sound_pool__resume, streamID);
}

void sound_pool__set_looping_platform(int streamID, int loop)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_sound_pool__set_looping, streamID, loop);
}

void sound_pool__stop_platform(int streamID)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_sound_pool__stop, streamID);
}

void sound_pool__unload_platform(int soundID)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_sound_pool__unload, soundID);
}

void sound_pool__release_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_sound_pool__release);
}
