#include "Component.h"
#include "../GameObject/GameObject.h"

CComponent::CComponent()
{
	bCanEverTick = true;
	bIsStarted = false;
}

void CComponent::Start() 
{
	bIsStarted = true;
}

void CComponent::Tick(float dt) { }
