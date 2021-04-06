#pragma once
#include "../Character.h"

class CEnemyCharacter final :
    public CCharacter
{
public :
    // 적 캐릭터의 방향을 나타냅니다.
    /// - 이 값은 AIBHMoveToPlayer 클래스에서 설정됩니다.
    FVector2 Direction;

public :
    class CWaveController* WaveController;

private :
    class CAIBehaviorController* AIBehaviorController;
    class CCircleCollision* BodyCollision;



public :
    virtual void Initialize() override;
    virtual void Start() override;
    virtual void Tick(float dt) override;

protected:
    virtual void OnCharacterDie() override;

private :
    void OnOverlapped(class CCollision * other);

};

