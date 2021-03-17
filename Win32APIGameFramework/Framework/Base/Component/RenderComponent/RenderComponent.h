#pragma once
#include "../Component.h"

// �׸��� ����� �߰��� ������Ʈ
class CRenderComponent abstract :
    public CComponent
{
public :
    // render �޼��尡 ȣ��ǵ��� �� �������� �����մϴ�.
    bool bUseRender;

private :
    // �׸��� ������ ��Ÿ���ϴ�.
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

