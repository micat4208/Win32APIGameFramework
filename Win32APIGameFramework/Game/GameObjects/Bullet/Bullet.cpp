#include "Bullet.h"

#include "../../Components/BulletRenderer/BulletRenderer.h"

#include "../../../Framework/Base/Component/Collision/CircleCollision/CircleCollision.h"


CBullet::CBullet() : MaxDistance(1000.0f) { }

void CBullet::Initialize()
{
	__super::Initialize();

	bRecyclable = false;
}

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

void CBullet::InitializeBullet(FVector2 beginPosition, FVector2 direction, float speed)
{
	SetPosition(BeginPosition = beginPosition);
	Direction = direction;
	Speed = speed;
}

void CBullet::BulletMove(float dt)
{
	SetPosition(GetPosition() + (Direction * Speed * dt));

	// 현재 총알의 위치가 발사된 지점에서 MaxDistance 이상 이동했다면
	// 총알 오브젝트를 재활용 가능한 상태로 설정합니다.
	if (FVector2::Distance(BeginPosition, GetPosition()) >= MaxDistance)
		SetCanRecyclable(true);
}

void CBullet::OnRecycleStarted()
{
}
