#include "RenderComponent.h"

#include "../../GameObject/GameObject.h"
#include "../../Scene/Scene.h"

CRenderComponent::CRenderComponent()
{
	bUseRender = true;
	SortingOrder = 0;
}

void CRenderComponent::SetSortingOrder(__int32 order)
{
	SortingOrder = order;
	GetOwner()->OwnerScene->bNeedSort = true;
}
