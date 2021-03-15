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

	// 등록한 SubManager 객체 해제
	for (auto iter = ManagerClasses.begin();
		iter != ManagerClasses.end(); ++iter)
	{
		iter->second->ReleaseManagerClass();
		delete iter->second;
	}

	ManagerClasses.clear();

	GameInstance = nullptr;
}
