#include "GameObject.h"

#include "../../Single/CollisionManager/CollisionManager.h"

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

void CGameObject::Tick(float dt) 
{ 
	// 생성된 컴포넌트가 존재한다면
	if (CreatedComponents.size() > 0)
	{
		// UsedComponent list 로 요소를 추가합니다.
		for (auto component : CreatedComponents)
			UsedComponents.push_back(component);
		CreatedComponents.clear();
	}

	// 제거될 컴포넌트가 존재한다면
	if (DestroyedComponents.size() > 0)
	{
		for (auto component : DestroyedComponents)
		{
			ReleaseComponent(component);
			UsedComponents.remove(component);
		}

	}

	// 추가된 컴포넌트들의 Start() 메서드와 Tick() 메서드를 호출합니다.
	if (UsedComponents.size() > 0)
	{
		for (auto component : UsedComponents)
		{
			if (component->bBeDestroy) continue;

			if (!component->bIsStarted)
				component->Start();

			if (component->bCanEverTick)
				component->Tick(dt);
		}
	}
}

void CGameObject::OnDestory() 
{
	// 생성된 컴포넌트가 존재한다면 
	if (CreatedComponents.size() > 0)
	{
		for (auto component : CreatedComponents)
			RemoveComponent(component);
		CreatedComponents.clear();
	}

	// 사용중인 컴포넌트를 제거합니다.
	for (auto component : UsedComponents)
		RemoveComponent(component);
	UsedComponents.clear();
}

void CGameObject::Release() 
{ 
	CObject::Release(); 

	// 생성된 컴포넌트가 존재한다면
	if (CreatedComponents.size() > 0)
	{
		for (auto component : CreatedComponents)
		{
			RemoveComponent(component);
			DeleteObj(component);
		}
	}

	// 사용중인 컴포넌트 해제
	for (auto component : UsedComponents)
	{
		RemoveComponent(component);
		DeleteObj(component);
	}
	CreatedComponents.clear();
	UsedComponents.clear();
}

void CGameObject::RemoveComponent(CComponent* component)
{
	component->bBeDestroy = true;

	if (IsA<CCollision>(component))
		CCollisionManager::Instance()->UnRegisterCollision(Cast<CCollision>(component));
	else if (IsA<CRenderComponent>(component))
		OwnerScene->UnRegisterRenderComponent(Cast<CRenderComponent>(component));

	DestroyedComponents.push_back(component);
}

void CGameObject::ReleaseComponent(CComponent* component)
{
	if (!component->bBeDestroy) return;
	DeleteObj(component);

}

void CGameObject::RegisterNewRenderComponent(CRenderComponent* newRenderComponent)
{
	OwnerScene->RegisterNewRenderComponent(newRenderComponent);
}

