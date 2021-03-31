#include "GameScene.h"

#include "Game/GameObjects/Characters/PlayerableCharacter/PlayerableCharacter.h"
#include "Game/GameObjects/Characters/EnemyCharacter/EnemyCharacter.h"
#include "Game/GameObjects/WaveController/WaveController.h"

#include "Framework/Base/Component/Collision/Collision.h"


void CGameScene::Initialize()
{
	CScene::Initialize();

	// WaveController 를 생성합니다.
	NewObject<CWaveController>(TEXT("WaveController"));

	// GameScene 에서 기본적으로 생성될 게임 오브젝트를 추가합니다.
	NewObject<CPlayerableCharacter>(TEXT("PlayerableCharacter"));

	//NewObject<CEnemyCharacter>(TEXT("EnemyCharacter"))->SetPosition(
	//	FVector2(WND_WIDTH / 2, WND_HEIGHT / 2));

}

void CGameScene::RegisterCharacter(CCollision* body, CCharacter* ownerCharacter)
{
	AllocatedCharacter.insert(make_pair(body, ownerCharacter));
}
