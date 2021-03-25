#pragma once
#include <fmod.h>
#include "../Component.h"

#ifndef AUDIO_DEFINE
#define AUDIO_DEFINE

#define AUDIO_VOLUME_MIN        0.0f
#define AUDIO_VOLUME_MAX        1.0f

#endif

class CAudioComponent :
    public CComponent
{
private :
    FMOD_SOUND* Sound;
    FMOD_CHANNEL* Channel;
    float Volume;
    FMOD_BOOL IsPlaying;

public :
    void InitializeAudioComponent(const char* path, bool bLoop);

    virtual void Initialize() override;
    virtual void Tick(float dt) override;
    virtual void Release() override;

public :
    void Play();
    void Pause();
    void Stop();
    void Resume();
    void VolumeUp();
    void VolumeDown();
    void SetVolume(float volume);



};

