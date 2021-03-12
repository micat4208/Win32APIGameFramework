#include "GameInstance.h"

#include "../SceneManager/SceneManager.h"

CGameInstance::CGameInstance()
{
}

void CGameInstance::Initialize()
{
	CObject::Initialize();

	RegisterManagerClass<CSceneManager>();
}

void CGameInstance::Release()
{
	CObject::Release();

	// ����� SubManager ��ü ����
	for (auto iter = ManagerClasses.begin();
		iter != ManagerClasses.end(); ++iter)
	{
		delete iter->second;
		iter->second->ReleaseManagerClass();
	}

	ManagerClasses.clear();

	GameInstance = nullptr;
}
