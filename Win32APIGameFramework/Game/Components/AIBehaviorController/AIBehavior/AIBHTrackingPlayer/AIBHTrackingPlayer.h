#pragma once
#include "../AIBehavior.h"
#include "../../../../../Framework/Structrues/Vector2/Vector2.h"

// �÷��̾� ĳ���͸� �����ϴ� �ൿ�� ��Ÿ���ϴ�.
class CAIBHTrackingPlayer :
    public CAIBehavior
{
private :
    // ���� ��ǥ�� ��Ÿ���ϴ�.
    class CPlayerableCharacter* TrackingTarget;

    // ���� �ӷ�
    float Speed;

    // ����
    FVector2 Direction;

    // ���� ���� �ּ� ���� �ð�
    float DirectionUpdateMinDelay;

    // ���� ���� �ִ� ���� �ð�
    float DirectionUpdateMaxDelay;

    // ���� ���� ���� �ð�
    float DirectionUpdateDelay;

    // ������ ���� ���� �ð�
    float LastDirectionUpdatedTime;

public :
    virtual void InitializeBehaivor() override;
    virtual void StartBehaivor() override;
    virtual void BehaviorTick(float dt) override;

private :
    // ���� ������ �����մϴ�.
    void UpdateDirection();

    // �÷��̾ �����մϴ�.
    void TrackingPlayer(float dt);

public :
    FORCEINLINE FVector2 GetDirection() const
    { return Direction; }

};

