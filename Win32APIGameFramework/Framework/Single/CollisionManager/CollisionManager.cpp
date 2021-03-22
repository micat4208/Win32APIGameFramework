#include "CollisionManager.h"

#include "../../Base/GameObject/GameObject.h"
#include "../../Base/Component/Collision/Collision.h"

bool CCollisionManager::DoCollisionTestCircleToCircle(CCollision* collision1, CCollision* collision2)
{
	float distance = FVector2::Distance(
		collision1->GetOwner()->GetPosition(), collision2->GetOwner()->GetPosition());

	// collision1 �� ������
	float radius1 = (collision1->GetRect().right - collision1->GetRect().left) * 0.5f;

	// collision2 �� ������
	float radius2 = (collision2->GetRect().right - collision2->GetRect().left) * 0.5f;

	// collision1 �� collision2 �� ������ ��� ���� / ��ġ�� �ʾ��� ��� ������ ��ȯ�մϴ�.
	return distance < (radius1 + radius2);
}

bool CCollisionManager::DoCollisionTestRectToRect(CCollision* collision1, CCollision* collision2)
{
	// collision1 �� collision2 �� ������ ��� �� / ��ġ�� �ʾ��� ��� ������ ��ȯ�մϴ�.
	if (collision1->GetRect().left > collision2->GetRect().right) return false;
	else if (collision1->GetRect().right < collision2->GetRect().left) return false;
	else if (collision1->GetRect().top > collision2->GetRect().bottom) return false;
	else if (collision1->GetRect().bottom < collision2->GetRect().top) return false;
	
	return true;
}

bool CCollisionManager::DoCollisionTestRectToCircle(CCollision* rect, CCollision* circle)
{
	// ���� ������
	float circleRadius = ((circle->GetRect().right) - (circle->GetRect().left)) * 0.5f;

	// ���� �߽� ��ġ
	FVector2 circleCenter = FVector2(
		circle->GetRect().right - circleRadius,
		circle->GetRect().bottom - circleRadius);

	// ���� ������ X ��ǥ�� �簢���� ���� ���� ���� ��ġ�ϴ���,
	// ���� ������ Y ��ǥ�� �簢���� ���� ���� ���� ��ġ�ϴ��� �˻��մϴ�.
	if ((rect->GetRect().left <= circleCenter.X && circleCenter.X <= rect->GetRect().right) ||
		(rect->GetRect().top <= circleCenter.Y && circleCenter.Y <= rect->GetRect().bottom))
	{

		/// ���� ������ ���̸�ŭ Ȯ��� �簢���� ���մϴ�.
		RECT rc = {
			rect->GetRect().left - circleRadius,
			rect->GetRect().top - circleRadius,
			rect->GetRect().right + circleRadius,
			rect->GetRect().bottom + circleRadius,
		};
		
		/// ���� �߽����� Ȯ��� �簢�� ���ο� ��ġ���� �ʴ��� Ȯ���մϴ�.
		if		(circleCenter.X < rc.left)
			return false;
		else if (circleCenter.X > rc.right)
			return false;
		else if (circleCenter.Y < rc.top)
			return false;
		else if (circleCenter.Y > rc.bottom)
			return false;

		/// �ƴ϶�� ��ħ
		return true;
	}

	FVector2 rPos[4] =
	{
		// �簢���� ���� ���
		FVector2(rect->GetRect().left, rect->GetRect().top),
		// �簢���� ���� �ϴ�
		FVector2(rect->GetRect().left, rect->GetRect().bottom),
		// �簢���� ���� ��� 
		FVector2(rect->GetRect().right, rect->GetRect().top),
		// �簢���� ���� �ϴ� 
		FVector2(rect->GetRect().right, rect->GetRect().bottom)
	};

	/// �簢���� �� ������ �� �ϳ��� �� ���� ��ġ�Ѵٸ� ��ħ
	for (auto pos : rPos)
		if (FVector2::Distance(circleCenter, pos) <= circleRadius) return true;
	
	/// �ƴ϶�� ��ġ�� ����.
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

	// ��ϵ� �浹ü�� 2 �� �̸��̶�� �˻����� �ʽ��ϴ�.
	if (UsedCollisions.size() < 2) return;

	auto iter1 = UsedCollisions.begin();
	auto iter1Fin = --UsedCollisions.end();

	for (; iter1 != iter1Fin; ++iter1)
	{
		auto iter2 = iter1;
		++iter2;

		auto iter2Fin = UsedCollisions.end();

		// �浹ü�� Start() �޼��尡 ȣ����� �ʾҴٸ� �浹 �˻� X
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
