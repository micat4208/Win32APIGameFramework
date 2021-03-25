#include "PlayerableCharacter.h"

#include "../../../../Framework/Statics/GameplayStatics.h"
#include "../../../../Framework/Base/Component/Collision/CircleCollision/CircleCollision.h"

#include "../../../Components/CharacterRenderer/CharacterRenderer.h"
#include "../../../Components/PlayerAttack/PlayerAttack.h"


void CPlayerableCharacter::Initialize()
{
	CGameObject::Initialize();

	LOG(TEXT("CPlayerableCharacter::Initialize()"));
	LOG((CCollisionManager::Instance() == nullptr));
	RegisterCharacter(AddComponent<CCircleCollision>());

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
