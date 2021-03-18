#include "BulletRenderer.h"

#include "../../../Framework/Base/GameObject/GameObject.h"



void CBulletRenderer::Render(HDC hdc)
{
	auto center = GetOwner()->GetPosition();
	auto radius = 20.0f;

	Ellipse(hdc,
		center.X - radius,
		center.Y - radius,
		center.X + radius,
		center.Y + radius);
}
