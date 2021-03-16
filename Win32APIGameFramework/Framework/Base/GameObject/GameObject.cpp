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

	// �߰��� ������Ʈ���� Start() �޼���� Tick() �޼��带 ȣ���մϴ�.
	for (auto component : UsedComponents)
	{
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

	// ������ ������Ʈ�� �����Ѵٸ�
	if (CreatedComponents.size() > 0)
	{
		for (auto component : CreatedComponents)
		{
			DeleteObj(component);
		}
	}

	// ������� ������Ʈ ����
	for (auto component : UsedComponents)
	{
		DeleteObj(component);
	}
	CreatedComponents.clear();
	UsedComponents.clear();
}

void CGameObject::RegisterNewRenderComponent(CRenderComponent* newRenderComponent)
{
	OwnerScene->RegisterNewRenderComponent(newRenderComponent);
}
