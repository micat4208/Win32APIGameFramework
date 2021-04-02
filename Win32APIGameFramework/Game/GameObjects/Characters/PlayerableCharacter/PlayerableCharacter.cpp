#include "PlayerableCharacter.h"

#include "Framework/Single/PlayerManager/PlayerManager.h"

#include "Framework/Statics/GameplayStatics.h"

#include "Framework/Base/Component/Collision/CircleCollision/CircleCollision.h"
#include "Framework/Base/Component/RenderComponent/SpriteRenderer/SpriteRenderer.h"
#include "Game/Components/CharacterRenderer/CharacterRenderer.h"
#include "Game/Components/PlayerAttack/PlayerAttack.h"


void CPlayerableCharacter::Initialize()
{
	__super::Initialize();

	AddTag(TAG_PLAYER_CHARACTER);
	RegisterCharacter(AddComponent<CCircleCollision>());
	CPlayerManager::Instance()->RegisterPlayerableCharacter(this);

	SpriteRenderer->InitializeSpriteRenderer(
		/*path               = */ TEXT("Resources/Sprite/T_Player.bmp"),
		/*spriteWidth        = */ 48.0f,
		/*spriteHeight       = */ 48.0f,
		/*drawWidth          = */ 96.0f,
		/*drawHeight         = */ 96.0f,
		/*bUseTransparentBlt = */ true,
		/*dwRop              = */ NULL,
		/*crTransparent)     = */ RGB(255, 0, 255));

	SpriteRenderer->RegisterSpriteAnimInfo(
		TEXT("Test"),
		FSpriteAnimInfo(0.5f, 0, 2, 0));
	SpriteRenderer->SetSortingOrder(10);
	SpriteRenderer->ChangeAnimation(TEXT("Test"));
}

void CPlayerableCharacter::Start()
{
	CGameObject::Start();

	AddComponent<CCharacterRenderer>()->bDrawLine = true;
	PlayerAttack = AddComponent<CPlayerAttack>();

}

void CPlayerableCharacter::Tick(float dt)
{
	CGameObject::Tick(dt);
	InputKey(dt);
}

void CPlayerableCharacter::OnCharacterDie()
{
}

void CPlayerableCharacter::InputKey(float dt)
{
	if (GetAsyncKeyState(MOVE_LEFT))
		SetPosition(GetPosition() + FVector2(-400.0f, 0.0f) * dt);
	else if (GetAsyncKeyState(MOVE_RIGHT))
		SetPosition(GetPosition() + FVector2(400.0f, 0.0f) * dt);

	if (GetAsyncKeyState(MOVE_UP))
		SetPosition(GetPosition() + FVector2(0.0f, -400.0f) * dt);
	else if (GetAsyncKeyState(MOVE_DOWN))
		SetPosition(GetPosition() + FVector2(0.0f, 400.0f) * dt);

	// 마우스 위치를 얻습니다.
	MousePosition = CGameplayStatics::GetMousePosition();

	PlayerAttack->AttackDirection = FVector2::Direction(
		GetPosition(), MousePosition);
}
