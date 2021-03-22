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

bool CCollisionManager::DoCollisionTestRectToCircle(CCollision* rect, CCollision* circle)
{
	// 원의 반지름
	float circleRadius = ((circle->GetRect().right) - (circle->GetRect().left)) * 0.5f;

	// 원의 중심 위치
	FVector2 circleCenter = FVector2(
		circle->GetRect().right - circleRadius,
		circle->GetRect().bottom - circleRadius);

	// 원의 중점의 X 좌표가 사각형의 가로 영역 내에 위치하는지,
	// 원의 중점의 Y 좌표가 사각형의 세로 영역 내에 위치하는지 검사합니다.
	if ((rect->GetRect().left <= circleCenter.X && circleCenter.X <= rect->GetRect().right) ||
		(rect->GetRect().top <= circleCenter.Y && circleCenter.Y <= rect->GetRect().bottom))
	{

		/// 원의 반지름 길이만큼 확장된 사각형을 구합니다.
		RECT rc = {
			rect->GetRect().left - circleRadius,
			rect->GetRect().top - circleRadius,
			rect->GetRect().right + circleRadius,
			rect->GetRect().bottom + circleRadius,
		};
		
		/// 원의 중심점이 확장된 사각형 내부에 위치하지 않는지 확인합니다.
		if		(circleCenter.X < rc.left)
			return false;
		else if (circleCenter.X > rc.right)
			return false;
		else if (circleCenter.Y < rc.top)
			return false;
		else if (circleCenter.Y > rc.bottom)
			return false;

		/// 아니라면 겹침
		return true;
	}

	FVector2 rPos[4] =
	{
		// 사각형의 좌측 상단
		FVector2(rect->GetRect().left, rect->GetRect().top),
		// 사각형의 좌측 하단
		FVector2(rect->GetRect().left, rect->GetRect().bottom),
		// 사각형의 우측 상단 
		FVector2(rect->GetRect().right, rect->GetRect().top),
		// 사각형의 우측 하단 
		FVector2(rect->GetRect().right, rect->GetRect().bottom)
	};

	/// 사각형의 네 꼭지점 중 하나라도 원 내에 위치한다면 겹침
	for (auto pos : rPos)
		if (FVector2::Distance(circleCenter, pos) <= circleRadius) return true;
	
	/// 아니라면 겹치지 않음.
	return false;
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
					if (DoCollisionTestRectToCircle(*iter1, *iter2))
					{
						(*iter1)->OnOverlapped(*iter2);
						(*iter2)->OnOverlapped(*iter1);
					}
				}
				break;

			case ECollisionType::Circle:
				if ((*iter2)->GetCollisionType() == ECollisionType::Rect)
				{
					if (DoCollisionTestRectToCircle(*iter2, *iter1))
					{
						(*iter1)->OnOverlapped(*iter2);
						(*iter2)->OnOverlapped(*iter1);
					}
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

void CCollisionManager::RegisterCollision(CCollision* collision)
{
	CreatedCollisions.push_back(collision);
}

void CCollisionManager::UnRegisterCollision(CCollision* collision)
{
	DestroyedCollisions.push_back(collision);
}
