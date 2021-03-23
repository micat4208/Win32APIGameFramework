#include "PlayerAttack.h"

#include "../../../Framework/Base/Scene/Scene.h"

#include "../../GameObjects/Bullet/Bullet.h"


void CPlayerAttack::Initialize()
{
	__super::Initialize();

	Length = 50.0f;
}

void CPlayerAttack::Tick(float dt)
{
	__super::Tick(dt);

	// 왼쪽 마우스 클릭 입력 -> 미사일 발사
	if (GetAsyncKeyState(VK_LBUTTON))
		FireMissile();
}

void CPlayerAttack::FireMissile()
{
	// CBullet 오브젝트 추가
	CBullet * newBullet = GetOwner()->OwnerScene->NewObject<CBullet>();
	newBullet->SetPosition(GetOwner()->GetPosition() + (AttackDirection * Length));

	newBullet->InitializeBullet(AttackDirection, 600.0f);
}
