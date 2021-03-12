#include "GameObject.h"
#include "../Scene/Scene.h"

CGameObject::CGameObject()
{
	OwnerScene = nullptr;

	bCanEverTick = true;
	bIsStarted = bBeDestroy = false;
}

void CGameObject::Initialize() 
{  CObject::Initialize(); }

void CGameObject::Start()
{ bIsStarted = true; }

void CGameObject::Tick(float dt) { }

void CGameObject::OnDestory() { }

void CGameObject::Release() 
{ CObject::Release(); }
