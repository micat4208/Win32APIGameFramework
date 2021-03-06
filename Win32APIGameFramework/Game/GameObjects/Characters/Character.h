#pragma once
#include "../../../Framework/Base/GameObject/GameObject.h"

class CCharacter abstract :
    public CGameObject
{
protected :
    float MaxHp;
    float Hp;

    class CSpriteRenderer* SpriteRenderer;

public :
    virtual void Initialize() override;
    virtual void Start() override;

public :
    virtual void ApplyDamage(
        CCharacter* damageCauser, 
        CComponent* componentCauser, 
        float damage);

protected :
    void RegisterCharacter(class CCollision* body);
    virtual void OnCharacterDie() PURE;


public :
    FORCEINLINE float GetMaxHp() const
    { return MaxHp; }
    FORCEINLINE float GetHp() const
    { return Hp; }




};

