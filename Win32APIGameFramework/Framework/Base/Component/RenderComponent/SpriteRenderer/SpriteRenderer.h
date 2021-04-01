#pragma once
#include "Framework/Base/Component/RenderComponent/RenderComponent.h"

#include "Framework/Bitmap/Bitmap.h"


class CSpriteRenderer :
    public CRenderComponent
{
private :
    // �׸� ��������Ʈ �̹���
    CBitmap* DrawSpriteImage;

    // ��������Ʈ ��ȯ ������
    float SpriteDelay;

    // ���������� ��ȯ�� �ð��� ��Ÿ���ϴ�.
    float LastSpriteChangedTime;

public :
    virtual void Initialize() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;

public :
    // ����� �̹����� �ε��մϴ�.
    void InitializeSpriteRenderer(LPCTSTR path, float spriteDelay);

};

