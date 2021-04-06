#include "EnemyCharacter.h"

#include "Framework/Base/Component/Collision/CircleCollision/CircleCollision.h"
#include "Framework/Base/Component/RenderComponent/SpriteRenderer/SpriteRenderer.h"

#include "Game/Components/CharacterRenderer/CharacterRenderer.h"
#include "Game/Components/AIBehaviorController/AIBehaviorController.h"
#include "Game/Components/AIBehaviorController/AIBehavior/AIBHTrackingPlayer/AIBHTrackingPlayer.h"

#include "Game/GameObjects/WaveController/WaveController.h"

void CEnemyCharacter::Initialize()
{
	__super::Initialize();

	AddComponent<CCharacterRenderer>();
	BodyCollision = AddComponent<CCircleCollision>();
	AIBehaviorController = AddComponent<CAIBehaviorController>();

	// 행동 등록
	AIBehaviorController->RegisterBehavior<CAIBHTrackingPlayer>();


	SpriteRenderer->InitializeSpriteRenderer(
		/*path               = */ TEXT("Resources/Sprite/T_Enemy.bmp"),
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

}

void CEnemyCharacter::Start()
{
	CGameObject::Start();

	// 행동 제어 시작
	AIBehaviorController->StartBehaviorControl();

	RegisterCharacter(BodyCollision);

	AddTag(TAG_ENEMY_CHARACTER);
	
	BodyCollision->SetRadius(30.0f);
	BodyCollision->OverlapEvents.push_back(
		[this](CCollision* other) { OnOverlapped(other); });

}

void CEnemyCharacter::Tick(float dt)
{
	__super::Tick(dt);

	tstring actionName = (Direction.Length() < 0.1f) ? TEXT("Idle_") : TEXT("Move_");
	actionName += (Direction.X > 0) ? TEXT("Right") : TEXT("Left");

	SpriteRenderer->ChangeAnimation(actionName);
}

void CEnemyCharacter::OnCharacterDie()
{
	WaveController->DestroyEnemy(this);
}

void CEnemyCharacter::OnOverlapped(CCollision* other)
{
}
