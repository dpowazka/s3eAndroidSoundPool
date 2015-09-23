/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "soundpool.h"


// Define S3E_EXT_SKIP_LOADER_CALL_LOCK on the user-side to skip LoaderCallStart/LoaderCallDone()-entry.
// e.g. in s3eNUI this is used for generic user-side IwUI-based implementation.
#ifndef S3E_EXT_SKIP_LOADER_CALL_LOCK
#if defined I3D_ARCH_MIPS || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)) || defined I3D_ARCH_NACLX86_64
// For platforms missing stack-switching (MIPS, WP8, Android-x86, NaCl, etc.) make loader-entry via LoaderCallStart/LoaderCallDone() on the user-side.
#define LOADER_CALL_LOCK
#endif
#endif


#include "soundpool_interface.h"

static soundpoolFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0xecd4b8c8, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: soundpool");

        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xecd4b8c8, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool soundpoolAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

void sound_pool__init(int maxStreams)
{
    IwTrace(SOUNDPOOL_VERBOSE, ("calling soundpool[0] func: sound_pool__init"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_sound_pool__init);
#endif

    g_Ext.m_sound_pool__init(maxStreams);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_sound_pool__init);
#endif

    return;
}

int sound_pool__load(const char* path, int priority)
{
    IwTrace(SOUNDPOOL_VERBOSE, ("calling soundpool[1] func: sound_pool__load"));

    if (!_extLoad())
        return -1;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_sound_pool__load);
#endif

    int ret = g_Ext.m_sound_pool__load(path, priority);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_sound_pool__load);
#endif

    return ret;
}

int sound_pool__play(int soundID, float leftVolume, float rightVolume, int priority, int loop, float rate)
{
    IwTrace(SOUNDPOOL_VERBOSE, ("calling soundpool[2] func: sound_pool__play"));

    if (!_extLoad())
        return -1;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_sound_pool__play);
#endif

    int ret = g_Ext.m_sound_pool__play(soundID, leftVolume, rightVolume, priority, loop, rate);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_sound_pool__play);
#endif

    return ret;
}

void sound_pool__pause(int streamID)
{
    IwTrace(SOUNDPOOL_VERBOSE, ("calling soundpool[3] func: sound_pool__pause"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_sound_pool__pause);
#endif

    g_Ext.m_sound_pool__pause(streamID);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_sound_pool__pause);
#endif

    return;
}

void sound_pool__resume(int streamID)
{
    IwTrace(SOUNDPOOL_VERBOSE, ("calling soundpool[4] func: sound_pool__resume"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_sound_pool__resume);
#endif

    g_Ext.m_sound_pool__resume(streamID);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_sound_pool__resume);
#endif

    return;
}

void sound_pool__set_looping(int streamID, int loop)
{
    IwTrace(SOUNDPOOL_VERBOSE, ("calling soundpool[5] func: sound_pool__set_looping"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_sound_pool__set_looping);
#endif

    g_Ext.m_sound_pool__set_looping(streamID, loop);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_sound_pool__set_looping);
#endif

    return;
}

void sound_pool__stop(int streamID)
{
    IwTrace(SOUNDPOOL_VERBOSE, ("calling soundpool[6] func: sound_pool__stop"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_sound_pool__stop);
#endif

    g_Ext.m_sound_pool__stop(streamID);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_sound_pool__stop);
#endif

    return;
}

void sound_pool__unload(int soundID)
{
    IwTrace(SOUNDPOOL_VERBOSE, ("calling soundpool[7] func: sound_pool__unload"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_sound_pool__unload);
#endif

    g_Ext.m_sound_pool__unload(soundID);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_sound_pool__unload);
#endif

    return;
}

void sound_pool__release()
{
    IwTrace(SOUNDPOOL_VERBOSE, ("calling soundpool[8] func: sound_pool__release"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_sound_pool__release);
#endif

    g_Ext.m_sound_pool__release();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_sound_pool__release);
#endif

    return;
}