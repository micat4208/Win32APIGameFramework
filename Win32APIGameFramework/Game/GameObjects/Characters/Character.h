#pragma once
#include "../../../Framework/Base/GameObject/GameObject.h"

class CCharacter abstract :
    public CGameObject
{
protected :
    float Hp;

public :
    virtual void Start() override;

public :
    virtual void ApplyDamage(
        CCharacter* damageCauser, 
        CComponent* componentCauser, 
        float damage);

protected :
    void RegisterCharacter(class CCollision* body);




};

