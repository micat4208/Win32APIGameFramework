#include "EnemyCharacter.h"

#include "../../../Components/CharacterRenderer/CharacterRenderer.h"
#include "../../../Components/AIBehaviorController/AIBehaviorController.h"

#include "../../../../Framework/Base/Component/Collision/CircleCollision/CircleCollision.h"

void CEnemyCharacter::Start()
{
	CGameObject::Start();

	AddComponent<CCharacterRenderer>();
	BodyCollision = AddComponent<CCircleCollision>();
	AIBehaviorController = AddComponent<CAIBehaviorController>();

	// 행동 등록
	{

	}

	RegisterCharacter(BodyCollision);

	AddTag(TAG_ENEMY_CHARACTER);
	
	BodyCollision->SetRadius(30.0f);
	BodyCollision->OverlapEvents.push_back(
		[this](CCollision* other) { OnOverlapped(other); });

}

void CEnemyCharacter::OnOverlapped(CCollision* other)
{
}
