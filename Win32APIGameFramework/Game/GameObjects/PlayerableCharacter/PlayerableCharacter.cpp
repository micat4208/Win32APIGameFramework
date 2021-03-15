#include "PlayerableCharacter.h"

void CPlayerableCharacter::Initialize()
{
	CGameObject::Initialize();
}

void CPlayerableCharacter::Tick(float dt)
{
	CGameObject::Tick(dt);

	if (GetAsyncKeyState(VK_SPACE))
	{
		LOG(TEXT("VK_SPACE!"));
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		LOG(TEXT("VK_LEFT!"));
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		LOG(TEXT("VK_RIGHT!"));
	}
}
