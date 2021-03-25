#include "AudioComponent.h"

#include "../../GameObject/GameObject.h"
#include "../../Scene/Scene.h"

void CAudioComponent::InitializeAudioComponent(const char* path, bool bLoop)
{
	FMOD_System_CreateSound(SoundSystem, path,
		(bLoop ? FMOD_LOOP_NORMAL : FMOD_DEFAULT), 0, &Sound);

	Channel = nullptr;
	Volume = AUDIO_VOLUME_MAX * 0.5f;

	FMOD_System_Create(&SoundSystem);
	FMOD_System_Init(SoundSystem, 32, FMOD_INIT_NORMAL, NULL);
}

void CAudioComponent::Initialize()
{
	__super::Initialize();
}

void CAudioComponent::Tick(float dt)
{
	__super::Tick(dt);

	FMOD_Channel_IsPlaying(Channel, &IsPlaying);

	if (IsPlaying)
		FMOD_System_Update(SoundSystem);

	else GetOwner()->OwnerScene->Destroy(GetOwner());

}

void CAudioComponent::Release()
{
	__super::Release();

	FMOD_Sound_Release(Sound);
}

void CAudioComponent::Play()
{
	FMOD_System_PlaySound(SoundSystem, Sound, NULL, false, &Channel);
}

void CAudioComponent::Pause()
{
	FMOD_Channel_SetPaused(Channel, true);
}

void CAudioComponent::Stop()
{
	FMOD_Channel_Stop(Channel);
}

void CAudioComponent::Resume()
{
	FMOD_Channel_SetPaused(Channel, false);
}

void CAudioComponent::VolumeUp()
{
	if (Volume < AUDIO_VOLUME_MAX)
		Volume += 0.1f;
	FMath::Clamp(Volume, AUDIO_VOLUME_MIN, AUDIO_VOLUME_MAX);

	FMOD_Channel_SetVolume(Channel, Volume);
}

void CAudioComponent::VolumeDown()
{
	if (Volume > AUDIO_VOLUME_MIN)
		Volume -= 0.1f;
	FMath::Clamp(Volume, AUDIO_VOLUME_MIN, AUDIO_VOLUME_MAX);

	FMOD_Channel_SetVolume(Channel, Volume);
}

void CAudioComponent::SetVolume(float volume)
{
	Volume = volume;
	FMath::Clamp(Volume, AUDIO_VOLUME_MIN, AUDIO_VOLUME_MAX);
	FMOD_Channel_SetVolume(Channel, Volume);
}
