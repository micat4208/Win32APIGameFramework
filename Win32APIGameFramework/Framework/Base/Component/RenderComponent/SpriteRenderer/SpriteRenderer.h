#pragma once
#include "Framework/Base/Component/RenderComponent/RenderComponent.h"

#include "Framework/Structrues/SpriteAnimInfo/SpriteAnimInfo.h"

#include "Framework/Bitmap/Bitmap.h"


class CSpriteRenderer :
    public CRenderComponent
{
private :
    // 그릴 스프라이트 이미지
    CBitmap* DrawSpriteImage;

    // TransparentBlt 함수를 사용함을 나타냅니다.
    bool bUseTransparentBlt;

    // TransparentBlt 사용 시 제외시킬 색상을 나타냅니다.
    COLORREF CRTransparent;
    // StretchBlt 사용 시 이미지 출력 방식을 나타냅니다.
    DWORD DWRop;

    // 스프라이트 이미지 너비 / 높이
    float SpriteWidth;
    float SpriteHeight;

    // 그려지는 이미지 크기
    float DrawWidth;
    float DrawHeight;

    // 현재 사용되는 스프라이트 애니메이션 이름 / 정보
    tstring SpriteAnimName;
    FSpriteAnimInfo SpriteAnimInfo;

    // 스프라이트 애니메이션 정보들
    map<tstring, FSpriteAnimInfo> SpriteAnimInfos;

public :
    virtual void Initialize() override;
    virtual void Tick(float dt) override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;

public :
    // 사용할 이미지를 로드합니다.
    void InitializeSpriteRenderer(
        LPCTSTR     path, 
        float       spriteWidth, 
        float       spriteHeight,
        float       drawWidth,
        float       drawHeight,
        bool        bUseTransparentBlt = false,
        DWORD       dwRop = SRCCOPY,
        COLORREF    crTransparent = RGB(0, 0, 0));

    // 스프라이트 애니메이션 정보를 등록합니다.
    void RegisterSpriteAnimInfo(tstring animName, FSpriteAnimInfo newSpriteAnimInfo);

    // 애니메이션을 변경합니다.
    /// - newAnimationName : 변경시킬 스프라이트 애니메이션 이름
    /// - bChangeForce : 애니메이션 강제 변경
    ///   false 라면 현재 재생중인 애니메이션 이름과 일치하는 애니메이션을 
    ///   재생하려고 하는 경우 무시되도록 합니다.
    void ChangeAnimation(tstring newAnimationName, bool bChangeForce = false);

};

