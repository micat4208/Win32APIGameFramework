#pragma once
#include "../Character.h"

class CEnemyCharacter final :
    public CCharacter
{
public :
    // �� ĳ������ ������ ��Ÿ���ϴ�.
    /// - �� ���� AIBHMoveToPlayer Ŭ�������� �����˴ϴ�.
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

