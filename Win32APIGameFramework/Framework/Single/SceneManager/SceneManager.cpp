#include "SceneManager.h"

#include "../../../Game/Scenes/GameScene/GameScene.h"


void CSceneManager::InitializeManagerClass()
{
	CurrentScene = NextScene = nullptr;

	// 첫 번째 씬을 설정합니다.
	LoadScene<CGameScene>();
}

void CSceneManager::ReleaseManagerClass()
{
	CManagerClassBase::ReleaseManagerClass();

	if (CurrentScene != nullptr)
	{
		DeleteObj(CurrentScene);
	}

	if (NextScene != nullptr)
	{
		DeleteObj(NextScene);
	}
}

void CSceneManager::Tick(float dt)
{
	// 다음 씬이 존재한다면
	if (NextScene != nullptr)
	{
		// 현재 플레이중인 씬이 존재한다면
		if (CurrentScene != nullptr)
		{
			DeleteObj(CurrentScene);
		}

		// 다음 씬을 초기화합니다.
		CurrentScene = NextScene;
		NextScene = nullptr;
	}

	if (CurrentScene != nullptr)
		CurrentScene->Tick(dt);
}
