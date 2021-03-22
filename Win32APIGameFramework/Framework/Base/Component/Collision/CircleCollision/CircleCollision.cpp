#include "CircleCollision.h"

#include "../../../GameObject/GameObject.h"

CCircleCollision::CCircleCollision()
{
	CollisionType = ECollisionType::Circle;
}

void CCircleCollision::SetRadius(float radius)
{
	FVector2 center = GetOwner()->GetPosition();
	rc = {
		(LONG)(center.X - radius),
		(LONG)(center.Y - radius),
		(LONG)(center.X + radius),
		(LONG)(center.Y + radius)
	};
}
