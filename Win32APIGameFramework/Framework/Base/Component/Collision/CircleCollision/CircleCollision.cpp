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
		center.X - radius,
		center.Y - radius,
		center.X + radius,
		center.Y + radius
	};
}
