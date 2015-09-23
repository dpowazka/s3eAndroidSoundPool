/*
java implementation of the sound_pool extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import java.io.IOException;
import com.ideaworks3d.marmalade.LoaderAPI;
// Comment in the following line if you want to use ResourceUtility
// import com.ideaworks3d.marmalade.ResourceUtility;
import android.media.SoundPool;
//import android.media.SoundPool.Builder;
import android.media.AudioManager;
import android.content.res.AssetFileDescriptor;

class soundpool
{
    private SoundPool sound_pool;

    public void sound_pool__init(int maxStreams)
    {
        /* Right way:
        SoundPool.Builder builder = new SoundPool.Builder();
        builder.setMaxStreams(maxStreams);
        sound_pool = builder.build();
        */
        sound_pool = new SoundPool(maxStreams,  AudioManager.STREAM_MUSIC, 0);
    }

    public int sound_pool__load(String path, int priority)
    {
        try {
            AssetFileDescriptor afd = LoaderAPI.getActivity().getAssets().openFd(path);
            return sound_pool.load(afd, priority);
        }catch(IOException e) {
            System.out.println(e);
            return -1;
        }
    }

    public int sound_pool__play(int soundID, float leftVolume, float rightVolume, int priority, int loop, float rate)
    {
        return sound_pool.play(soundID, leftVolume, rightVolume, priority, loop, rate);
    }

    public void sound_pool__pause(int streamID)
    {
        sound_pool.pause(streamID);
    }

    public void sound_pool__resume(int streamID)
    {
        sound_pool.resume(streamID);
    }

    public void sound_pool__set_looping(int streamID, int loop)
    {
        sound_pool.setLoop(streamID, loop);
    }

    public void sound_pool__stop(int streamID)
    {
        sound_pool.stop(streamID);
    }

    public void sound_pool__unload(int soundID)
    {
        sound_pool.unload(soundID);
    }

    public void sound_pool__release()
    {
        sound_pool.release();    
    }
}
