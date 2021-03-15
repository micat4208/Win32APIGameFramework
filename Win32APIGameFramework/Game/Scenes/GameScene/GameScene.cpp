#include "GameScene.h"

#include "../../GameObjects/PlayerableCharacter/PlayerableCharacter.h"

void CGameScene::Initialize()
{
	CScene::Initialize();

	// GameScene 에서 기본적으로 생성될 게임 오브젝트를 추가합니다.
	NewObject<CPlayerableCharacter>(TEXT("PlayerableCharacter"));




}
