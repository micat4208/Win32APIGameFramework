#include "GameScene.h"

#include "../../GameObjects/Characters/PlayerableCharacter/PlayerableCharacter.h"

void CGameScene::Initialize()
{
	CScene::Initialize();

	// GameScene ���� �⺻������ ������ ���� ������Ʈ�� �߰��մϴ�.
	NewObject<CPlayerableCharacter>(TEXT("PlayerableCharacter"));




}
