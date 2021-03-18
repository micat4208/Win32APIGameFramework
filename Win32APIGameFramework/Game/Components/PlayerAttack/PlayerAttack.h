#pragma once
#include "../../../Framework/Base/Component/Component.h"

class CPlayerAttack :
    public CComponent
{

public :
    FVector2 AttackDirection;
    float Length;

public :
    virtual void Initialize() override;
    virtual void Tick(float dt) override;

private :
    void FireMissile();



};

