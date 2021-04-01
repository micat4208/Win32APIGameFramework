#include "TitlePressEnterKey.h"

#include "Framework/Single/SceneManager/SceneManager.h"

#include "Game/Scenes/GameScene/GameScene.h"

void CTitlePressEnterKey::Tick(float dt)
{
	CRenderComponent::Tick(dt);

	if (GetAsyncKeyState(VK_RETURN))
	{
		CSceneManager::Instance()->LoadScene<CGameScene>();
	}
}


void CTitlePressEnterKey::Render(HDC hdc)
{
	LPCTSTR pressEnterKey = TEXT("Press Enter Key.");

	SetTextAlign(hdc, TA_CENTER);
	TextOut(hdc, WND_WIDTH * 0.5f, WND_HEIGHT * 0.5f,
		pressEnterKey, lstrlen(pressEnterKey));
}
