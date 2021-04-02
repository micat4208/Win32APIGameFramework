#pragma once
#include "Framework/Base/Component/RenderComponent/RenderComponent.h"

#include "Framework/Structrues/SpriteAnimInfo/SpriteAnimInfo.h"

#include "Framework/Bitmap/Bitmap.h"


class CSpriteRenderer :
    public CRenderComponent
{
private :
    // �׸� ��������Ʈ �̹���
    CBitmap* DrawSpriteImage;

    // TransparentBlt �Լ��� ������� ��Ÿ���ϴ�.
    bool bUseTransparentBlt;

    // TransparentBlt ��� �� ���ܽ�ų ������ ��Ÿ���ϴ�.
    COLORREF CRTransparent;
    // StretchBlt ��� �� �̹��� ��� ����� ��Ÿ���ϴ�.
    DWORD DWRop;

    // ��������Ʈ �̹��� �ʺ� / ����
    float SpriteWidth;
    float SpriteHeight;

    // �׷����� �̹��� ũ��
    float DrawWidth;
    float DrawHeight;

    // ���� ���Ǵ� ��������Ʈ �ִϸ��̼� �̸� / ����
    tstring SpriteAnimName;
    FSpriteAnimInfo SpriteAnimInfo;

    // ��������Ʈ �ִϸ��̼� ������
    map<tstring, FSpriteAnimInfo> SpriteAnimInfos;

public :
    virtual void Initialize() override;
    virtual void Tick(float dt) override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;

public :
    // ����� �̹����� �ε��մϴ�.
    void InitializeSpriteRenderer(
        LPCTSTR     path, 
        float       spriteWidth, 
        float       spriteHeight,
        float       drawWidth,
        float       drawHeight,
        bool        bUseTransparentBlt = false,
        DWORD       dwRop = SRCCOPY,
        COLORREF    crTransparent = RGB(0, 0, 0));

    // ��������Ʈ �ִϸ��̼� ������ ����մϴ�.
    void RegisterSpriteAnimInfo(tstring animName, FSpriteAnimInfo newSpriteAnimInfo);

    // �ִϸ��̼��� �����մϴ�.
    /// - newAnimationName : �����ų ��������Ʈ �ִϸ��̼� �̸�
    /// - bChangeForce : �ִϸ��̼� ���� ����
    ///   false ��� ���� ������� �ִϸ��̼� �̸��� ��ġ�ϴ� �ִϸ��̼��� 
    ///   ����Ϸ��� �ϴ� ��� ���õǵ��� �մϴ�.
    void ChangeAnimation(tstring newAnimationName, bool bChangeForce = false);

};

