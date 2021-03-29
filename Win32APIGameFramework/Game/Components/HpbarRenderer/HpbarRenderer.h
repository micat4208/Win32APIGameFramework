#pragma once

#include "../../../Framework/Base/Component/RenderComponent/RenderComponent.h"

class CHpbarRenderer final :
    public CRenderComponent
{
private :
    class CCharacter* OwnerCharacter;

    // 플레이어 캐릭터임을 나타냅니다.
    /// - true 일 경우 푸른색으로 표시되며, false 일 경우 붉은색으로 표시됩니다.
    bool bIsPlayer;

    HBRUSH MyBrush, OldBrush;
    HPEN MyPen, OldPen;

public :
    virtual void Initialize() override;
    virtual void Start() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
};
