#pragma once
#include "../Character.h"

class CEnemyCharacter final :
    public CCharacter
{

public :
    class CWaveController* WaveController;

private :
    class CAIBehaviorController* AIBehaviorController;
    class CCircleCollision* BodyCollision;



public :
    virtual void Initialize() override;
    virtual void Start() override;

protected:
    virtual void OnCharacterDie() override;

private :
    void OnOverlapped(class CCollision * other);

};

