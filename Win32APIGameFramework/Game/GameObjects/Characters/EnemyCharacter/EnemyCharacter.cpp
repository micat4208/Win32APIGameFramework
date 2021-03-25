#include "EnemyCharacter.h"

#include "../../../Components/CharacterRenderer/CharacterRenderer.h"

#include "../../../../Framework/Base/Component/Collision/CircleCollision/CircleCollision.h"

void CEnemyCharacter::Start()
{
	CGameObject::Start();

	AddComponent<CCharacterRenderer>();
	BodyCollision = AddComponent<CCircleCollision>();

	RegisterCharacter(BodyCollision);

	
	BodyCollision->SetRadius(30.0f);
	BodyCollision->OverlapEvents.push_back(
		[this](CCollision* other) { OnOverlapped(other); });

}

void CEnemyCharacter::OnOverlapped(CCollision* other)
{
	LOG(TEXT("HP = ") << Hp);
	

}
