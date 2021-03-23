#include "Collision.h"

void CCollision::OnOverlapped(CCollision* other)
{
	if (OverlapEvents.size() > 0)
	{
		for (auto overlapEvent : OverlapEvents)
		{
			overlapEvent(other);
		}
	}

}
