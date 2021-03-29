#pragma once
#include "../ManagerClassBase/ManagerClassBase.h"

// 플레이어를 관리합니다.
class CPlayerManager final :
    public CManagerClassBase<CPlayerManager>
{
private :
    // 플레이어 캐릭터를 나타냅니다.
    class CPlayerableCharacter* PlayerableCharacter;

public :
    virtual void InitializeManagerClass() override;

public :
    FORCEINLINE void RegisterPlayerableCharacter(
        class CPlayerableCharacter* newPlayerableCharacter)
    { PlayerableCharacter = newPlayerableCharacter; }

    FORCEINLINE class CPlayerableCharacter* GetPlayerableCharacter() const
    { return PlayerableCharacter; }


};

