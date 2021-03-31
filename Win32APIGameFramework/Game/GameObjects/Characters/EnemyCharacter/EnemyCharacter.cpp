#include "EnemyCharacter.h"

#include "Framework/Base/Component/Collision/CircleCollision/CircleCollision.h"

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

void CEnemyCharacter::OnCharacterDie()
{
	WaveController->DestroyEnemy(this);
}

void CEnemyCharacter::OnOverlapped(CCollision* other)
{
}
