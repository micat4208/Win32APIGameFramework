#include "Character.h"

#include "../../Scenes/GameScene/GameScene.h"

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
}

void CCharacter::RegisterCharacter(CCollision* body)
{
	Cast<CGameScene>(OwnerScene)->RegisterCharacter(body, this);
}
