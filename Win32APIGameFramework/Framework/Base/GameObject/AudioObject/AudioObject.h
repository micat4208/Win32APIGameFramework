#pragma once
#include "../GameObject.h"

class CAudioObject :
    public CGameObject
{
private :
    class CAudioComponent* AudioComponent;

public :
    virtual void Initialize() override;

public :
    void InitializeAudio(
        const char* path, bool bLoop, 
        float volume, bool bBeginPlay = true);

};

