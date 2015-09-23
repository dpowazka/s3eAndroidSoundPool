/*
 * Internal header for the soundpool extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef SOUNDPOOL_INTERNAL_H
#define SOUNDPOOL_INTERNAL_H

#include "s3eTypes.h"
#include "soundpool.h"
#include "soundpool_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult soundpoolInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult soundpoolInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void soundpoolTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void soundpoolTerminate_platform();
void sound_pool__init_platform(int maxStreams);

int sound_pool__load_platform(const char* path, int priority);

int sound_pool__play_platform(int soundID, float leftVolume, float rightVolume, int priority, int loop, float rate);

void sound_pool__pause_platform(int streamID);

void sound_pool__resume_platform(int streamID);

void sound_pool__set_looping_platform(int streamID, int loop);

void sound_pool__stop_platform(int streamID);

void sound_pool__unload_platform(int soundID);

void sound_pool__release_platform();


#endif /* !SOUNDPOOL_INTERNAL_H */