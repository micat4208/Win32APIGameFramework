#include "GameScene.h"

#include "../../GameObjects/PlayerableCharacter/PlayerableCharacter.h"

void CGameScene::Initialize()
{
	CScene::Initialize();

	// GameScene ���� �⺻������ ������ ���� ������Ʈ�� �߰��մϴ�.
	NewObject<CPlayerableCharacter>(TEXT("PlayerableCharacter"));




}
