#include "BulletRenderer.h"

#include "../../../Framework/Base/GameObject/GameObject.h"



void CBulletRenderer::Render(HDC hdc)
{
	auto center = GetOwner()->GetPosition();
	auto radius = 20.0f;

	if (FMath::IsIn(center.X, 0.0f, (float)WND_WIDTH) &&
		FMath::IsIn(center.Y, 0.0f, (float)WND_HEIGHT))
	{
		Ellipse(hdc,
			center.X - radius,
			center.Y - radius,
			center.X + radius,
			center.Y + radius);
	}
}
