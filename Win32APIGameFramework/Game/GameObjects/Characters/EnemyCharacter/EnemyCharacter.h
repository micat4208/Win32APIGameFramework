#pragma once
#include "../Character.h"

class CEnemyCharacter final :
    public CCharacter
{

private :
    class CAIBehaviorController* AIBehaviorController;
    class CCircleCollision* BodyCollision;

public :
    virtual void Initialize() override;
    virtual void Start() override;

private :
    void OnOverlapped(class CCollision * other);

};

