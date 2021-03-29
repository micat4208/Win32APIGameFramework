#include "BulletRenderer.h"

#include "../../GameObjects/\Bullet/Bullet.h"



void CBulletRenderer::Render(HDC hdc)
{
	auto ownerBullet = Cast<CBullet>(GetOwner());

	if (ownerBullet->GetCanRecyclable()) return;

	auto center = ownerBullet->GetPosition();
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
