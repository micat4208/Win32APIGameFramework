#pragma once
#include "../../../Framework/Base/Component/RenderComponent/RenderComponent.h"

class CBulletRenderer final :
    public CRenderComponent
{
public :
    virtual void Render(HDC hdc) override;

};

