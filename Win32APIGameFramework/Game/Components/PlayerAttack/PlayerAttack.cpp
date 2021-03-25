#include "PlayerAttack.h"

#include "../../Scenes/GameScene/GameScene.h"

#include "../../GameObjects/Bullet/Bullet.h"
#include "../../../Framework/Base/GameObject/AudioObject/AudioObject.h"
#include "../../GameObjects/Characters/PlayerableCharacter/PlayerableCharacter.h"

#include "../../../Framework/Base/Component/Collision/CircleCollision/CircleCollision.h"

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

	// 왼쪽 마우스 클릭 입력 -> 미사일 발사
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
	// 오디오 오브젝트 생성
	//auto audioObject = GetOwner()->OwnerScene->NewObject<CAudioObject>();
	//audioObject->InitializeAudio("Resources/Audio/Fire_Missile.wav", false, 0.4f);

	// CBullet 오브젝트 추가
	CBullet* newBullet = Cast<CBullet>(BulletPool->GetRecycledObject());
	newBullet = (newBullet == nullptr) ?
		BulletPool->RegisterRecyclableObject<CBullet>(
			GetOwner()->OwnerScene->NewObject<CBullet>()) : newBullet;

	FVector2 beginPosition = GetOwner()->GetPosition() + (AttackDirection * Length);

	newBullet->InitializeBullet(beginPosition, AttackDirection, 600.0f);

	/*
	newBullet->GetBulletCollision()->OverlapEvents.push_back(
		[this, newBullet](CCollision* other)
		{
			if (other->GetOwner() != GetOwner() &&
				other->GetOwner() != newBullet)
			{
				Cast<CGameScene>(GetOwner()->OwnerScene)->GetCharacter(other)->ApplyDamage(
					Cast<CPlayerableCharacter>(GetOwner()), this, 20.0f);
			}
		});
		*/
}
