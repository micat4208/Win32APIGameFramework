#pragma once
#include "../../../Framework/Base/Component/Component.h"

class CPlayerAttack :
    public CComponent
{

public :
    FVector2 AttackDirection;
    float Length;
    float AttackDelay;

private :
    class CObjectPool* BulletPool;

public :
    virtual void Initialize() override;
    virtual void Tick(float dt) override;
    virtual void Release() override;

private :
    void FireMissile();




};

