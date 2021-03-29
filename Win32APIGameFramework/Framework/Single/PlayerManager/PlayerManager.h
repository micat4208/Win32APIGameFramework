#pragma once
#include "../ManagerClassBase/ManagerClassBase.h"

// �÷��̾ �����մϴ�.
class CPlayerManager final :
    public CManagerClassBase<CPlayerManager>
{
private :
    // �÷��̾� ĳ���͸� ��Ÿ���ϴ�.
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

