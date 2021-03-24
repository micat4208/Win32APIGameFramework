#pragma once
#include "../../../Framework/Base/GameObject/GameObject.h"
#include "../../../Framework/Interfaces/ObjectPoolable.h"

class CBullet final :
    public CGameObject,
    public IObjectPoolable
{
private :
    class CCircleCollision* BulletCollision;

    FVector2 BeginPosition;
    FVector2 Direction;
    float Speed;
    const float MaxDistance;

    bool bRecyclable;

public :
    CBullet();
    virtual void Initialize() override;
    virtual void Start() override;
    virtual void Tick(float dt) override;

public :
    void InitializeBullet(FVector2 beginPosition, FVector2 direction, float speed);

private :
    void BulletMove(float dt);


public :
    FORCEINLINE virtual void SetCanRecyclable(bool bCanRecyclable) override
    { bRecyclable = bCanRecyclable; }
    FORCEINLINE virtual bool GetCanRecyclable() const override
    { return bRecyclable; }

    virtual void OnRecycleStarted() override;

};

