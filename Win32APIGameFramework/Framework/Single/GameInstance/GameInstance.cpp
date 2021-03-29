#include "GameInstance.h"

#include "../SceneManager/SceneManager.h"
#include "../CollisionManager/CollisionManager.h"
#include "../PlayerManager/PlayerManager.h"

CGameInstance::CGameInstance()
{
}

void CGameInstance::Initialize()
{
	CObject::Initialize();
	Hdc = ::GetDC(Hwnd);
	GameInstance = this;

	RegisterManagerClass<CCollisionManager>();
	RegisterManagerClass<CPlayerManager>();
	RegisterManagerClass<CSceneManager>();
}

void CGameInstance::Release()
{
	CObject::Release();

	// ����� SubManager ��ü ����
	for (auto iter = ManagerClasses.begin();
		iter != ManagerClasses.end(); ++iter)
	{
		iter->second->ReleaseManagerClass();
		delete iter->second;
	}

	ManagerClasses.clear();

	GameInstance = nullptr;
	ReleaseDC(Hwnd, Hdc);
}
