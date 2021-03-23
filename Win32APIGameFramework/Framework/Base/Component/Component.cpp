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
