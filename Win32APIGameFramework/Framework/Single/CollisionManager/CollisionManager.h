#pragma once
#include "../ManagerClassBase/ManagerClassBase.h"

class CCollisionManager final:
    public CManagerClassBase<CCollisionManager>
{
    // 충돌 처리를 할 객체들을 저장합니다.
    list<class CCollision*> UsedCollisions;
    list<class CCollision*> CreatedCollisions;
    list<class CCollision*> DestroyedCollisions;

private :
    // 원과 원 충돌 검사
    bool DoCollisionTestCircleToCircle(class CCollision* collision1, class CCollision* collision2);

    // 사각형과 사각형 충돌 검사
    bool DoCollisionTestRectToRect(class CCollision* collision1, class CCollision* collision2);

    // 원과 사각형 충돌 검사
    bool DoCollisionTestRectToCircle(class CCollision* rect, class CCollision* circle);

public :
    void DoCollisionTest();

    void RegisterCollision(class CCollision* collision);
    void UnRegisterCollision(class CCollision* collision);




};

