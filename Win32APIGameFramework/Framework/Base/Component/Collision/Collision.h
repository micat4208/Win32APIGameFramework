#pragma once
#include "../Component.h"
#include "../../../Enums/CollisionType.h"


// �浹ü�� ��Ÿ���� ���� ������Ʈ
class CCollision abstract :
    public CComponent
{
protected :
    // �浹ü�� ���� ������ ��Ÿ���ϴ�.
    RECT rc;

    // �浹ü Ÿ���� ��Ÿ���ϴ�.
    ECollisionType CollisionType;

public :
    FORCEINLINE virtual void OnOverlapped(CCollision* other) {}

public :
    FORCEINLINE ECollisionType GetCollisionType() const
    { return CollisionType; }

    FORCEINLINE const RECT& GetRect() const
    { return rc; }

    

};

