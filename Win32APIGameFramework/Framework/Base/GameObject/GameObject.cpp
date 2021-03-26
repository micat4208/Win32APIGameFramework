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

		// 적 캐릭터와 겹침 이벤트 처리

		for (auto component : DestroyedComponents)
		{
			if (IsA<CCollision>(component))
				CCollisionManager::Instance()->UnRegisterCollision(Cast<CCollision>(component));
			else if (IsA<CRenderComponent>(component))
				OwnerScene->UnRegisterRenderComponent(Cast<CRenderComponent>(component));

			UsedComponents.remove(component);
		}

	}

	// 추가된 컴포넌트들의 Start() 메서드와 Tick() 메서드를 호출합니다.
	for (auto component : UsedComponents)
	{
		if (component->bBeDestroy) continue;

		if (!component->bIsStarted)
			component->Start();

		if (component->bCanEverTick)
			component->Tick(dt);
	}
}

void CGameObject::OnDestory() { }

void CGameObject::Release() 
{ 
	CObject::Release(); 

	// 생성된 컴포넌트가 존재한다면
	if (CreatedComponents.size() > 0)
	{
		for (auto component : CreatedComponents)
		{
			DeleteObj(component);
		}
	}

	// 사용중인 컴포넌트 해제
	for (auto component : UsedComponents)
	{
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

void CGameObject::RegisterNewRenderComponent(CRenderComponent* newRenderComponent)
{
	OwnerScene->RegisterNewRenderComponent(newRenderComponent);
}

