#pragma once
#include "../Component.h"

// 그리는 기능이 추가된 컴포넌트
class CRenderComponent abstract :
    public CComponent
{
public :
    // render 메서드가 호출되도록 할 것인지를 결정합니다.
    bool bUseRender;

private :
    // 그리기 순서를 나타냅니다.
    __int32 SortingOrder;

public :
    CRenderComponent();

public :
    virtual void Render(HDC hdc) PURE;

public :
    void SetSortingOrder(__int32 order);

    FORCEINLINE __int32 GetSortingOrder() const
    { return SortingOrder; }

};

