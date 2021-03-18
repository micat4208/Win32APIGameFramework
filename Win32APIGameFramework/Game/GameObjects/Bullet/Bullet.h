#pragma once
#include "../../../Framework/Base/GameObject/GameObject.h"

class CBullet final :
    public CGameObject
{
private :
    FVector2 Direction;
    float Speed;

public :
    virtual void Start() override;
    virtual void Tick(float dt) override;

public :
    void InitializeBullet(FVector2 direction, float speed);

private :
    void BulletMove(float dt);

};

