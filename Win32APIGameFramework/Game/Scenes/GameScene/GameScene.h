#pragma once
#include "../../../Framework/Base/Scene/Scene.h"

class CGameScene final :
    public CScene
{
private :
    map<class CCollision*, class CCharacter*> AllocatedCharacter;

public :
    virtual void Initialize() override;

public :
    void RegisterCharacter(class CCollision* body, class CCharacter* ownerCharacter);

    FORCEINLINE class CCharacter* GetCharacter(class CCollision* collision)
    {
        auto findedCharacter = AllocatedCharacter.find(collision);

        return (findedCharacter == AllocatedCharacter.end()) ?
            nullptr : findedCharacter->second;
    }
    

};

