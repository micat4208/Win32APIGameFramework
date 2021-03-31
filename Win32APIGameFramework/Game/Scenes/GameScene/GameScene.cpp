#include "GameScene.h"

#include "Game/GameObjects/Characters/PlayerableCharacter/PlayerableCharacter.h"
#include "Game/GameObjects/Characters/EnemyCharacter/EnemyCharacter.h"
#include "Game/GameObjects/WaveController/WaveController.h"

#include "Framework/Base/Component/Collision/Collision.h"


void CGameScene::Initialize()
{
	CScene::Initialize();

	// WaveController �� �����մϴ�.
	NewObject<CWaveController>(TEXT("WaveController"));

	// GameScene ���� �⺻������ ������ ���� ������Ʈ�� �߰��մϴ�.
	NewObject<CPlayerableCharacter>(TEXT("PlayerableCharacter"));

	//NewObject<CEnemyCharacter>(TEXT("EnemyCharacter"))->SetPosition(
	//	FVector2(WND_WIDTH / 2, WND_HEIGHT / 2));

}

void CGameScene::RegisterCharacter(CCollision* body, CCharacter* ownerCharacter)
{
	AllocatedCharacter.insert(make_pair(body, ownerCharacter));
}
