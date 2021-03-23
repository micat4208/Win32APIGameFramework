#include "Bullet.h"

#include "../../Components/BulletRenderer/BulletRenderer.h"

#include "../../../Framework/Base/Component/Collision/CircleCollision/CircleCollision.h"


void CBullet::Start()
{
	CGameObject::Start();

	AddComponent<CBulletRenderer>();
	BulletCollision = AddComponent<CCircleCollision>();
}

void CBullet::Tick(float dt)
{
	CGameObject::Tick(dt);

	BulletMove(dt);
	BulletCollision->SetRadius(20.0f);
}

void CBullet::InitializeBullet(FVector2 direction, float speed)
{
	Direction = direction;
	Speed = speed;
}

void CBullet::BulletMove(float dt)
{
	SetPosition(GetPosition() + (Direction * Speed * dt));
}
