#include "TitleScene.h"

#include "Game/Components/TitlePressEnterKey/TitlePressEnterKey.h"

void CTitleScene::Initialize()
{
	CScene::Initialize();

	NewObject<CGameObject>()->AddComponent<CTitlePressEnterKey>();



}
