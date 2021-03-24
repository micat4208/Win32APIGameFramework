#include "PlayerAttack.h"

#include "../../../Framework/Base/Scene/Scene.h"

#include "../../GameObjects/Bullet/Bullet.h"

#include "../../../Framework/Util/ObjectPool.h"

#include "../../../Framework/Statics/GameplayStatics.h"


void CPlayerAttack::Initialize()
{
	__super::Initialize();

	BulletPool = NewObj<CObjectPool>();

	AttackDelay = 0.1f;

	Length = 50.0f;
}

void CPlayerAttack::Tick(float dt)
{
	__super::Tick(dt);

	// ���� ���콺 Ŭ�� �Է� -> �̻��� �߻�
	static float lastAttackTime = 0.0f;
	if (GetAsyncKeyState(VK_LBUTTON) && 
		(CGameplayStatics::GetTime() - lastAttackTime >= AttackDelay))
	{
		lastAttackTime = CGameplayStatics::GetTime();

		FireMissile();
	}
}

void CPlayerAttack::Release()
{
	__super::Release();
	DeleteObj(BulletPool);
}

void CPlayerAttack::FireMissile()
{
	// CBullet ������Ʈ �߰�


	CBullet* newBullet = Cast<CBullet>(BulletPool->GetRecycledObject());
	newBullet = (newBullet == nullptr) ?
		BulletPool->RegisterRecyclableObject<CBullet>(
			GetOwner()->OwnerScene->NewObject<CBullet>()) : newBullet;

	FVector2 beginPosition = GetOwner()->GetPosition() + (AttackDirection * Length);

	newBullet->InitializeBullet(beginPosition, AttackDirection, 600.0f);
}
