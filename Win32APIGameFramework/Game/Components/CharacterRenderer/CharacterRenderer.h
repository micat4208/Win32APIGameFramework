#pragma once
#include "../../../Framework/Base/Component/RenderComponent/RenderComponent.h"


class CCharacterRenderer final :
    public CRenderComponent
{

public :
    bool bDrawLine;

private :
    float Radius;

public :
    CCharacterRenderer();

public :
    virtual void Render(HDC hdc) override;

};

