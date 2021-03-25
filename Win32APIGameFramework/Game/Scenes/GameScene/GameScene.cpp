#include "GameScene.h"

#include "../../GameObjects/Characters/PlayerableCharacter/PlayerableCharacter.h"
#include "../../GameObjects/Characters/EnemyCharacter/EnemyCharacter.h"

#include "../../../Framework/Base/Component/Collision/Collision.h"

void CGameScene::Initialize()
{
	CScene::Initialize();

	// GameScene ���� �⺻������ ������ ���� ������Ʈ�� �߰��մϴ�.
	NewObject<CPlayerableCharacter>(TEXT("PlayerableCharacter"));

	NewObject<CEnemyCharacter>(TEXT("EnemyCharacter"))->SetPosition(
		FVector2(WND_WIDTH / 2, WND_HEIGHT / 2));





}

void CGameScene::RegisterCharacter(CCollision* body, CCharacter* ownerCharacter)
{
	AllocatedCharacter.insert(make_pair(body, ownerCharacter));
}
