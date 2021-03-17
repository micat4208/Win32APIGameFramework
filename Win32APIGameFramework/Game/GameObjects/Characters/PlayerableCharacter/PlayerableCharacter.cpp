#include "PlayerableCharacter.h"

#include "../../../Components/CharacterRenderer/CharacterRenderer.h"


void CPlayerableCharacter::Initialize()
{
	CGameObject::Initialize();

}

void CPlayerableCharacter::Start()
{
	CGameObject::Start();

	AddComponent<CCharacterRenderer>()->bDrawLine = true;
}

void CPlayerableCharacter::Tick(float dt)
{
	CGameObject::Tick(dt);

	if (GetAsyncKeyState(MOVE_LEFT))
		SetPosition(GetPosition() + FVector2(-10.0f, 0.0f));
	else if (GetAsyncKeyState(MOVE_RIGHT))
		SetPosition(GetPosition() + FVector2(10.0f, 0.0f));

	if (GetAsyncKeyState(MOVE_UP))
		SetPosition(GetPosition() + FVector2(0.0f, -10.0f));
	else if (GetAsyncKeyState(MOVE_DOWN))
		SetPosition(GetPosition() + FVector2(0.0f, 10.0f));
}
