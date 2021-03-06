#pragma once
#include "../Component.h"
#include "../../../Enums/CollisionType.h"



// 충돌체를 나타내기 위한 컴포넌트
class CCollision abstract :
    public CComponent
{

protected :

public :
    // 겹침이 발생했을 때 호출됩니다.
    vector< function<void(CCollision*)> > OverlapEvents;


protected :
    // 충돌체의 영역 정보를 나타냅니다.
    RECT rc;

    // 충돌체 타입을 나타냅니다.
    ECollisionType CollisionType;

public :
    virtual void OnOverlapped(CCollision* other);

public :

    FORCEINLINE ECollisionType GetCollisionType() const
    { return CollisionType; }

    FORCEINLINE const RECT& GetRect() const
    { return rc; }
};

