#include "PlayerableCharacter.h"

#include "Framework/Single/PlayerManager/PlayerManager.h"

#include "Framework/Statics/GameplayStatics.h"

#include "Framework/Base/Component/Collision/CircleCollision/CircleCollision.h"
#include "Framework/Base/Component/RenderComponent/SpriteRenderer/SpriteRenderer.h"
#include "Game/Components/CharacterRenderer/CharacterRenderer.h"
#include "Game/Components/PlayerAttack/PlayerAttack.h"
#include "Game/Components/PlayerMovement/PlayerMovement.h"


void CPlayerableCharacter::Initialize()
{
	__super::Initialize();

	bPrevJumpKeyPressedState = false;

	AddTag(TAG_PLAYER_CHARACTER);
	RegisterCharacter(AddComponent<CCircleCollision>());
	CPlayerManager::Instance()->RegisterPlayerableCharacter(this);
	PlayerMovement = AddComponent<CPlayerMovement>();

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
		TEXT("Idle_Left"), FSpriteAnimInfo(
			/*spriteDelay      = */	1.0f,
			/*spriteStartIndex = */	1,
			/*spriteEndIndex   = */	1,
			/*spriteYIndex     = */	0));

	SpriteRenderer->RegisterSpriteAnimInfo(
		TEXT("Idle_Right"), FSpriteAnimInfo(
			/*spriteDelay      = */	1.0f,
			/*spriteStartIndex = */	1,
			/*spriteEndIndex   = */	1,
			/*spriteYIndex     = */	1));

	SpriteRenderer->RegisterSpriteAnimInfo(
		TEXT("Move_Left"), FSpriteAnimInfo(
			/*spriteDelay      = */	0.1f, 
			/*spriteStartIndex = */	0,
			/*spriteEndIndex   = */	2,
			/*spriteYIndex     = */	0));

	SpriteRenderer->RegisterSpriteAnimInfo(
		TEXT("Move_Right"), FSpriteAnimInfo(
			/*spriteDelay      = */	0.1f,
			/*spriteStartIndex = */	0,
			/*spriteEndIndex   = */	2,
			/*spriteYIndex     = */	1));



	SpriteRenderer->SetSortingOrder(10);
	SpriteRenderer->ChangeAnimation(TEXT("Move_Right"));

	MaxMoveSpeed = 400.0f;
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
	MoveDirection = FVector2::ZeroVector();



	// 방향 설정
	if (GetAsyncKeyState(MOVE_LEFT))
	{
		MoveDirection += FVector2::LeftVector();
		PrevInputDirection = MoveDirection;
	}
	else if (GetAsyncKeyState(MOVE_RIGHT))
	{
		MoveDirection += FVector2::RightVector();
		PrevInputDirection = MoveDirection;
	}

	if (GetAsyncKeyState(MOVE_UP))
		MoveDirection += FVector2::UpVector();
	else if (GetAsyncKeyState(MOVE_DOWN))
		MoveDirection += FVector2::DownVector();

	// 벡터 정규화
	MoveDirection = MoveDirection.Normalized();
	SetPosition(GetPosition() + (MoveDirection * MaxMoveSpeed * dt));

	tstring actionName = (MoveDirection.Length() < 0.1f) ? TEXT("Idle_") : TEXT("Move_");
	actionName += (PrevInputDirection.X > 0) ? TEXT("Right") : TEXT("Left");

	SpriteRenderer->ChangeAnimation(actionName);


	// 마우스 위치를 얻습니다.
	MousePosition = CGameplayStatics::GetMousePosition();

	PlayerAttack->AttackDirection = FVector2::Direction(
		GetPosition(), MousePosition);



	// 점프 키 입력
	if (GetAsyncKeyState(VK_SPACE))
	{
		if (!bPrevJumpKeyPressedState)
		{
			bPrevJumpKeyPressedState = true;

			PlayerMovement->Jump();

			LOG(TEXT("Jump Key!"));
		}
	}
	else bPrevJumpKeyPressedState = false;
}
