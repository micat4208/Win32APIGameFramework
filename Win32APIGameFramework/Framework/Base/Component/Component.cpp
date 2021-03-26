#include "Component.h"
#include "../GameObject/GameObject.h"

CComponent::CComponent()
{
	bBeDestroy = false;
	bCanEverTick = true;
	bIsStarted = false;
}

void CComponent::Start() 
{
	bIsStarted = true;
}

void CComponent::Tick(float dt) { }

bool CComponent::HasTag(tstring tag) const
{
	for (auto componentTag : Tags)
		if (componentTag == tag) return true;

	return false;
}
