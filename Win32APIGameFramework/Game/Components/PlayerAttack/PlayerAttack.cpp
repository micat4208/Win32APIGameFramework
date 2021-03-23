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

	// ���� ���콺 Ŭ�� �Է� -> �̻��� �߻�
	if (GetAsyncKeyState(VK_LBUTTON))
		FireMissile();
}

void CPlayerAttack::FireMissile()
{
	// CBullet ������Ʈ �߰�
	CBullet * newBullet = GetOwner()->OwnerScene->NewObject<CBullet>();
	newBullet->SetPosition(GetOwner()->GetPosition() + (AttackDirection * Length));

	newBullet->InitializeBullet(AttackDirection, 600.0f);
}
