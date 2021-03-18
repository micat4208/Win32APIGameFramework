#include "Bullet.h"

#include "../../Components/BulletRenderer/BulletRenderer.h"

void CBullet::Start()
{
	CGameObject::Start();
	AddComponent<CBulletRenderer>();
}

void CBullet::Tick(float dt)
{
	BulletMove(dt);
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
