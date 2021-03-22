#pragma once
#include "../ManagerClassBase/ManagerClassBase.h"

class CCollisionManager final:
    public CManagerClassBase<CCollisionManager>
{
    // �浹 ó���� �� ��ü���� �����մϴ�.
    list<class CCollision*> UsedCollisions;
    list<class CCollision*> CreatedCollisions;
    list<class CCollision*> DestroyedCollisions;

private :
    // ���� �� �浹 �˻�
    bool DoCollisionTestCircleToCircle(class CCollision* collision1, class CCollision* collision2);

    // �簢���� �簢�� �浹 �˻�
    bool DoCollisionTestRectToRect(class CCollision* collision1, class CCollision* collision2);

    // ���� �簢�� �浹 �˻�
    bool DoCollisionTestRectToCircle(class CCollision* rect, class CCollision* circle);

public :
    void DoCollisionTest();

    void RegisterCollision(class CCollision* collision);
    void UnRegisterCollision(class CCollision* collision);




};

