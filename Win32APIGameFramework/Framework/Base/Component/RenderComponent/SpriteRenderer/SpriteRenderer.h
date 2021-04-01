#pragma once
#include "Framework/Base/Component/RenderComponent/RenderComponent.h"

#include "Framework/Bitmap/Bitmap.h"


class CSpriteRenderer :
    public CRenderComponent
{
private :
    // 그릴 스프라이트 이미지
    CBitmap* DrawSpriteImage;

    // 스프라이트 전환 딜레이
    float SpriteDelay;

    // 마지막으로 전환한 시간을 나타냅니다.
    float LastSpriteChangedTime;

public :
    virtual void Initialize() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;

public :
    // 사용할 이미지를 로드합니다.
    void InitializeSpriteRenderer(LPCTSTR path, float spriteDelay);

};

