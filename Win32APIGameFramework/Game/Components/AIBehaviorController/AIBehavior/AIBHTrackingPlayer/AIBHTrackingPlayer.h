#pragma once
#include "../AIBehavior.h"

// 플레이어 캐릭터를 추적하는 행동을 나타냅니다.
class AIBHTrackingPlayer :
    public CAIBehavior
{
private :
    // 추적 목표를 나타냅니다.
    class CPlayerableCharacter* TrackingTarget;

public :
    virtual void StartBehaivor() override;
};

