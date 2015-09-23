/*
Generic implementation of the soundpool extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "soundpool_internal.h"
s3eResult soundpoolInit()
{
    //Add any generic initialisation code here
    return soundpoolInit_platform();
}

void soundpoolTerminate()
{
    //Add any generic termination code here
    soundpoolTerminate_platform();
}

void sound_pool__init(int maxStreams)
{
	sound_pool__init_platform(maxStreams);
}

int sound_pool__load(const char* path, int priority)
{
	return sound_pool__load_platform(path, priority);
}

int sound_pool__play(int soundID, float leftVolume, float rightVolume, int priority, int loop, float rate)
{
	return sound_pool__play_platform(soundID, leftVolume, rightVolume, priority, loop, rate);
}

void sound_pool__pause(int streamID)
{
	sound_pool__pause_platform(streamID);
}

void sound_pool__resume(int streamID)
{
	sound_pool__resume_platform(streamID);
}

void sound_pool__set_looping(int streamID, int loop)
{
	sound_pool__set_looping_platform(streamID, loop);
}

void sound_pool__stop(int streamID)
{
	sound_pool__stop_platform(streamID);
}

void sound_pool__unload(int soundID)
{
	sound_pool__unload_platform(soundID);
}

void sound_pool__release()
{
	sound_pool__release_platform();
}
