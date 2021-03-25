#include "AudioObject.h"

#include "../../Component/AudioComponent/AudioComponent.h"

void CAudioObject::Initialize()
{
	__super::Initialize();
	AudioComponent = AddComponent<CAudioComponent>();
}

void CAudioObject::InitializeAudio(const char* path, 
	bool bLoop, float volume, bool bBeginPlay)
{
	AudioComponent->InitializeAudioComponent(path, bLoop);
	AudioComponent->SetVolume(volume);

	if (bBeginPlay)
		AudioComponent->Play();
}
