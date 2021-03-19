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

public :
    void DoCollisionTest();




};

