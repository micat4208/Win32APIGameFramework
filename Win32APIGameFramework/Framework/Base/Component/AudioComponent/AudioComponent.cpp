#include "AudioComponent.h"

#include "../../GameObject/GameObject.h"
#include "../../Scene/Scene.h"

void CAudioComponent::InitializeAudioComponent(const char* path, bool bLoop)
{
	// 사운드를 생성합니다.
	FMOD_System_CreateSound(SoundSystem, path,
		(bLoop ? FMOD_LOOP_NORMAL : FMOD_DEFAULT), 0, &Sound);
	/// - FMOD_LOOP_NORMAL : 사운드 무한 재생을 의미합니다.
	/// - FMOD_DEFAULT : 기본 재생 방식을 의미합니다.

	Channel = nullptr;
	Volume = AUDIO_VOLUME_MAX * 0.5f;

}

void CAudioComponent::Initialize()
{
	__super::Initialize();
}

void CAudioComponent::Tick(float dt)
{
	__super::Tick(dt);

	// 사운드 출력을 확인합니다.
	FMOD_Channel_IsPlaying(Channel, &IsPlaying);
	/// - 사운드 재생에 사용되는 채널을 전달합니다.
	/// - 사운드 출력 상태를 반환받을 변수를 전달합니다.

	// 재생중이라면 사운드 출력 상태를 갱신합니다.
	if (IsPlaying)
		FMOD_System_Update(SoundSystem);

	else GetOwner()->OwnerScene->Destroy(GetOwner());

}

void CAudioComponent::Release()
{
	__super::Release();

	// 사용된 사운드를 해제합니다.
	FMOD_Sound_Release(Sound);
}

void CAudioComponent::Play()
{
	// 사운드를 재생합니다
	FMOD_System_PlaySound(SoundSystem, Sound, NULL, false, &Channel);
	/// - 사운드 시스템을 전달합니다.
	/// - 플레이 시킬 사운드를 전달합니다.
	/// - 채널 그룹을 전달합니다. 사용하지 않을 때 NULL 을 전달합니다.
	/// - 채널을 일시 중단시킬 것인지를 결정합니다.
	/// - 재생시킬 때 사용될 채널을 전달합니다.
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
