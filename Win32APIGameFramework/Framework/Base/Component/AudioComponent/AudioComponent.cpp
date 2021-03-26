#include "AudioComponent.h"

#include "../../GameObject/GameObject.h"
#include "../../Scene/Scene.h"

void CAudioComponent::InitializeAudioComponent(const char* path, bool bLoop)
{
	// ���带 �����մϴ�.
	FMOD_System_CreateSound(SoundSystem, path,
		(bLoop ? FMOD_LOOP_NORMAL : FMOD_DEFAULT), 0, &Sound);
	/// - FMOD_LOOP_NORMAL : ���� ���� ����� �ǹ��մϴ�.
	/// - FMOD_DEFAULT : �⺻ ��� ����� �ǹ��մϴ�.

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

	// ���� ����� Ȯ���մϴ�.
	FMOD_Channel_IsPlaying(Channel, &IsPlaying);
	/// - ���� ����� ���Ǵ� ä���� �����մϴ�.
	/// - ���� ��� ���¸� ��ȯ���� ������ �����մϴ�.

	// ������̶�� ���� ��� ���¸� �����մϴ�.
	if (IsPlaying)
		FMOD_System_Update(SoundSystem);

	else GetOwner()->OwnerScene->Destroy(GetOwner());

}

void CAudioComponent::Release()
{
	__super::Release();

	// ���� ���带 �����մϴ�.
	FMOD_Sound_Release(Sound);
}

void CAudioComponent::Play()
{
	// ���带 ����մϴ�
	FMOD_System_PlaySound(SoundSystem, Sound, NULL, false, &Channel);
	/// - ���� �ý����� �����մϴ�.
	/// - �÷��� ��ų ���带 �����մϴ�.
	/// - ä�� �׷��� �����մϴ�. ������� ���� �� NULL �� �����մϴ�.
	/// - ä���� �Ͻ� �ߴܽ�ų �������� �����մϴ�.
	/// - �����ų �� ���� ä���� �����մϴ�.
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
