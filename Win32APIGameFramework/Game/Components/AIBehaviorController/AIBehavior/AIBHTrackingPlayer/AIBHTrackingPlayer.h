#pragma once
#include "../AIBehavior.h"

// �÷��̾� ĳ���͸� �����ϴ� �ൿ�� ��Ÿ���ϴ�.
class AIBHTrackingPlayer :
    public CAIBehavior
{
private :
    // ���� ��ǥ�� ��Ÿ���ϴ�.
    class CPlayerableCharacter* TrackingTarget;

public :
    virtual void StartBehaivor() override;
};

