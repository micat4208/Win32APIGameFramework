#include "RectCollision.h"
#include "../../../GameObject/GameObject.h"

CRectCollision::CRectCollision()
{
	CollisionType = ECollisionType::Rect;
}

void CRectCollision::SetBound(FVector2 min, FVector2 max)
{
	rc = {
		min.X,
		min.Y,
		max.X,
		max.Y };
}

void CRectCollision::SetBound(float width, float height)
{
	FVector2 center = GetOwner()->GetPosition();
	rc =
	{
		center.X - width * 0.5f,
		center.Y - height * 0.5f,
		center.X + width * 0.5f,
		center.Y + height * 0.5f
	};
}
