#pragma once
#include "../AIBehavior.h"
#include "../../../../../Framework/Structrues/Vector2/Vector2.h"

// 플레이어 캐릭터를 추적하는 행동을 나타냅니다.
class CAIBHTrackingPlayer :
    public CAIBehavior
{
private :
    // 추적 목표를 나타냅니다.
    class CPlayerableCharacter* TrackingTarget;

    // 추적 속력
    float Speed;

    // 방향
    FVector2 Direction;

    // 방향 갱신 최소 지연 시간
    float DirectionUpdateMinDelay;

    // 방향 갱신 최대 지연 시간
    float DirectionUpdateMaxDelay;

    // 방향 갱신 지연 시간
    float DirectionUpdateDelay;

    // 마지막 방향 갱신 시간
    float LastDirectionUpdatedTime;

public :
    virtual void InitializeBehaivor() override;
    virtual void StartBehaivor() override;
    virtual void BehaviorTick(float dt) override;

private :
    // 추적 방향을 갱신합니다.
    void UpdateDirection();

    // 플레이어를 추적합니다.
    void TrackingPlayer(float dt);

public :
    FORCEINLINE FVector2 GetDirection() const
    { return Direction; }

};

