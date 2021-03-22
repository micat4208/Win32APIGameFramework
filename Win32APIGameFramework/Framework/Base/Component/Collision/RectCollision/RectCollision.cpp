#include "RectCollision.h"
#include "../../../GameObject/GameObject.h"

CRectCollision::CRectCollision()
{
	CollisionType = ECollisionType::Rect;
}

void CRectCollision::SetBound(FVector2 min, FVector2 max)
{
	rc = {
		(LONG)(min.X),
		(LONG)(min.Y),
		(LONG)(max.X),
		(LONG)(max.Y) 
	};
}

void CRectCollision::SetBound(float width, float height)
{
	FVector2 center = GetOwner()->GetPosition();
	rc =
	{
		(LONG)(center.X - width * 0.5f),
		(LONG)(center.Y - height * 0.5f),
		(LONG)(center.X + width * 0.5f),
		(LONG)(center.Y + height * 0.5f)
	};
}
