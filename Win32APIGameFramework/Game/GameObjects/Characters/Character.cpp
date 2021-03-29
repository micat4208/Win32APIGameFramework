#include "Character.h"

#include "../../Components/HpbarRenderer/HpbarRenderer.h"

#include "../../Scenes/GameScene/GameScene.h"

void CCharacter::Initialize()
{
	__super::Initialize();
	AddComponent<CHpbarRenderer>();

	MaxHp = Hp = 100.0f;
}

void CCharacter::Start()
{
	__super::Start();
}

void CCharacter::ApplyDamage(
	CCharacter* damageCauser, 
	CComponent* componentCauser, 
	float damage)
{
	Hp -= damage;
	Hp = FMath::Clamp(Hp, 0.0f, MaxHp);
}

void CCharacter::RegisterCharacter(CCollision* body)
{
	Cast<CGameScene>(OwnerScene)->RegisterCharacter(body, this);
}
