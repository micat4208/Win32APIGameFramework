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
	// ������ ������Ʈ�� �����Ѵٸ�
	if (CreatedComponents.size() > 0)
	{
		// UsedComponent list �� ��Ҹ� �߰��մϴ�.
		for (auto component : CreatedComponents)
			UsedComponents.push_back(component);
		CreatedComponents.clear();
	}

	// ���ŵ� ������Ʈ�� �����Ѵٸ�
	if (DestroyedComponents.size() > 0)
	{
		for (auto component : DestroyedComponents)
		{
			ReleaseComponent(component);
			UsedComponents.remove(component);
		}

	}

	// �߰��� ������Ʈ���� Start() �޼���� Tick() �޼��带 ȣ���մϴ�.
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
	// ������ ������Ʈ�� �����Ѵٸ� 
	if (CreatedComponents.size() > 0)
	{
		for (auto component : CreatedComponents)
			RemoveComponent(component);
		CreatedComponents.clear();
	}

	// ������� ������Ʈ�� �����մϴ�.
	for (auto component : UsedComponents)
		RemoveComponent(component);
	UsedComponents.clear();
}

void CGameObject::Release() 
{ 
	CObject::Release(); 

	// ������ ������Ʈ�� �����Ѵٸ�
	if (CreatedComponents.size() > 0)
	{
		for (auto component : CreatedComponents)
		{
			RemoveComponent(component);
			DeleteObj(component);
		}
	}

	// ������� ������Ʈ ����
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

