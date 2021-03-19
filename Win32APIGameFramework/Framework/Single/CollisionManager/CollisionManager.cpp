#include "CollisionManager.h"

#include "../../Base/GameObject/GameObject.h"
#include "../../Base/Component/Collision/Collision.h"

bool CCollisionManager::DoCollisionTestCircleToCircle(CCollision* collision1, CCollision* collision2)
{
	float distance = FVector2::Distance(
		collision1->GetOwner()->GetPosition(), collision2->GetOwner()->GetPosition());

	// collision1 의 반지름
	float radius1 = (collision1->GetRect().right - collision1->GetRect().left) * 0.5f;

	// collision2 의 반지름
	float radius2 = (collision2->GetRect().right - collision2->GetRect().left) * 0.5f;

	// collision1 과 collision2 가 겹쳤을 경우 참을 / 겹치지 않았을 경우 거짓을 반환합니다.
	return distance < (radius1 + radius2);
}

bool CCollisionManager::DoCollisionTestRectToRect(CCollision* collision1, CCollision* collision2)
{
	// collision1 과 collision2 가 겹쳤을 경우 참 / 겹치지 않았을 경우 거짓을 반환합니다.
	if (collision1->GetRect().left > collision2->GetRect().right) return false;
	else if (collision1->GetRect().right < collision2->GetRect().left) return false;
	else if (collision1->GetRect().top > collision2->GetRect().bottom) return false;
	else if (collision1->GetRect().bottom < collision2->GetRect().top) return false;
	
	return true;
}

void CCollisionManager::DoCollisionTest()
{
	if (CreatedCollisions.size() != 0)
	{
		for (auto collision : CreatedCollisions)
			UsedCollisions.push_back(collision);
		UsedCollisions.clear();
	}

	if (DestroyedCollisions.size() != 0)
	{
		for (auto collisions : DestroyedCollisions)
			UsedCollisions.remove(collisions);
		DestroyedCollisions.clear();
	}

	// 등록된 충돌체가 2 개 미만이라면 검사하지 않습니다.
	if (UsedCollisions.size() < 2) return;

	auto iter1 = UsedCollisions.begin();
	auto iter1Fin = --UsedCollisions.end();

	for (; iter1 != iter1Fin; ++iter1)
	{
		auto iter2 = iter1;
		++iter2;

		auto iter2Fin = UsedCollisions.end();

		// 충돌체의 Start() 메서드가 호출되지 않았다면 충돌 검사 X
		if (!(*iter1)->bIsStarted) continue;
			
		for (; iter2 != iter2Fin; ++iter2)
		{
			if (!(*iter2)->bIsStarted) continue;
			if ((*iter1)->GetOwner()->bBeDestroy || (*iter2)->GetOwner()->bBeDestroy) continue;


			switch ((*iter1)->GetCollisionType())
			{
			case ECollisionType::Rect:
				if ((*iter2)->GetCollisionType() == ECollisionType::Rect)
				{
					if (DoCollisionTestRectToRect((*iter1), (*iter2)))
					{
						(*iter1)->OnOverlapped(*iter2);
						(*iter2)->OnOverlapped(*iter1);
					}
				}
				else if ((*iter2)->GetCollisionType() == ECollisionType::Circle)
				{
				}
				break;

			case ECollisionType::Circle:
				if ((*iter2)->GetCollisionType() == ECollisionType::Rect)
				{
				}
				else if ((*iter2)->GetCollisionType() == ECollisionType::Circle)
				{
					if (DoCollisionTestCircleToCircle((*iter1), (*iter2)))
					{
						(*iter1)->OnOverlapped(*iter2);
						(*iter2)->OnOverlapped(*iter1);
					}
				}
				break;
			}

		}

	}

}
