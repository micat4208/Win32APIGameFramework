#pragma once

#include "../../../Framework/Base/Component/RenderComponent/RenderComponent.h"

class CHpbarRenderer final :
    public CRenderComponent
{
private :
    class CCharacter* OwnerCharacter;

    // �÷��̾� ĳ�������� ��Ÿ���ϴ�.
    /// - true �� ��� Ǫ�������� ǥ�õǸ�, false �� ��� ���������� ǥ�õ˴ϴ�.
    bool bIsPlayer;

    HBRUSH MyBrush, OldBrush;
    HPEN MyPen, OldPen;

public :
    virtual void Initialize() override;
    virtual void Start() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
};
