#include "PlayerMovement.h"

#include "Framework/Base/GameObject/GameObject.h"

void CPlayerMovement::Initialize()
{
	CComponent::Initialize();

	YVelocity = 0.0f;
	JumpPower = 5.0f;
	MaxYVelocity = 50.0f;
}

void CPlayerMovement::Tick(float dt)
{
	CComponent::Tick(dt);

	// 캐릭터가 떨어지도록 합니다.
	FallDown(dt);
}

void CPlayerMovement::Jump()
{
	YVelocity = -JumpPower;
}


void CPlayerMovement::FallDown(float dt)
{
	YVelocity += 8.0f * dt;
	YVelocity = FMath::Clamp(YVelocity, -MaxYVelocity, MaxYVelocity);

	auto currentPosition = GetOwner()->GetPosition();
	currentPosition.Y += YVelocity;

	GetOwner()->SetPosition(currentPosition);
}
