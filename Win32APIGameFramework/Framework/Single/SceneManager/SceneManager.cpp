#include "SceneManager.h"

#include "../../../Game/Scenes/GameScene/GameScene.h"


void CSceneManager::InitializeManagerClass()
{
	CurrentScene = NextScene = nullptr;

	// ù ��° ���� �����մϴ�.
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
	// ���� ���� �����Ѵٸ�
	if (NextScene != nullptr)
	{
		// ���� �÷������� ���� �����Ѵٸ�
		if (CurrentScene != nullptr)
		{
			DeleteObj(CurrentScene);
		}

		// ���� ���� �ʱ�ȭ�մϴ�.
		CurrentScene = NextScene;
		NextScene = nullptr;
	}

	if (CurrentScene != nullptr)
		CurrentScene->Tick(dt);
}
