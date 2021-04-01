#pragma once
#include "Framework/Base/Component/RenderComponent/RenderComponent.h"

class CTitlePressEnterKey :
    public CRenderComponent
{
public:
    virtual void Tick(float dt) override;
    virtual void Render(HDC hdc) override;
};

