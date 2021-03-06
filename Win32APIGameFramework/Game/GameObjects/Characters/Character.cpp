#include "Character.h"

#include "Game/Components/HpbarRenderer/HpbarRenderer.h"
#include "Framework/Base/Component/RenderComponent/SpriteRenderer/SpriteRenderer.h"

#include "Game/Scenes/GameScene/GameScene.h"

void CCharacter::Initialize()
{
	__super::Initialize();

	SpriteRenderer = AddComponent<CSpriteRenderer>();
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
	if (FMath::Approximately(Hp, 0.0f))
		OnCharacterDie();
}

void CCharacter::RegisterCharacter(CCollision* body)
{
	Cast<CGameScene>(OwnerScene)->RegisterCharacter(body, this);
}
