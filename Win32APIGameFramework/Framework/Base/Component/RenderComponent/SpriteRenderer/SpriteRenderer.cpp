#include "SpriteRenderer.h"

#include "Framework/Base/GameObject/GameObject.h"

#include "Framework/Statics/GameplayStatics.h"

void CSpriteRenderer::Initialize()
{
	CRenderComponent::Initialize();
	DrawSpriteImage = nullptr;
	SpriteAnimName = TEXT("None");
}

void CSpriteRenderer::Tick(float dt)
{
	CRenderComponent::Tick(dt);

	if (SpriteAnimInfos.size() == 0) return;
	if (SpriteAnimName == TEXT("None")) return;

	if (CGameplayStatics::GetTime() - SpriteAnimInfo.LastSpriteChangedTime >= SpriteAnimInfo.SpriteDelay)
	{
		SpriteAnimInfo.LastSpriteChangedTime = CGameplayStatics::GetTime();
		SpriteAnimInfo.Next();
	}
}

void CSpriteRenderer::Render(HDC hdc)
{
	if (DrawSpriteImage == nullptr) return;

	FVector2 drawCenter = GetOwner()->GetPosition();

	if (bUseTransparentBlt)
	{
		TransparentBlt(
			// �̹����� ����� ��ġ �ڵ�
			hdc,

			// �̹����� �׸��� ������ ��ġ
			drawCenter.X - (DrawWidth * 0.5f),
			drawCenter.Y - (DrawHeight * 0.5f),

			// �׷��� �̹��� ũ��
			DrawWidth,
			DrawHeight,

			// �̹��� �ڵ�
			DrawSpriteImage->GetDC(),

			// ���� �̹����� �ڸ��� ������ X, Y ��ġ
			SpriteAnimInfo.SpriteIndex * SpriteWidth,
			SpriteAnimInfo.SpriteYIndex * SpriteHeight,

			// ���� �̹������� �߶� �ʺ�, ����
			SpriteWidth,
			SpriteHeight,

			// ���� �ȼ�
			CRTransparent);
	}
	else
	{
		StretchBlt(
			// �̹����� ����� ��ġ �ڵ�
			hdc,

			// �̹����� �׸��� ������ ��ġ
			drawCenter.X - (DrawWidth * 0.5f),
			drawCenter.Y - (DrawHeight * 0.5f),

			// �׷��� �̹��� ũ��
			DrawWidth,
			DrawHeight,

			// �̹��� �ڵ�
			DrawSpriteImage->GetDC(),

			// ���� �̹����� �ڸ��� ������ X, Y ��ġ
			SpriteAnimInfo.SpriteIndex * SpriteWidth,
			SpriteAnimInfo.SpriteYIndex * SpriteHeight,

			// ���� �̹������� �߶� �ʺ�, ����
			SpriteWidth,
			SpriteHeight,

			// �̹��� ��� ���
			DWRop);
	}


}

void CSpriteRenderer::Release()
{
	CRenderComponent::Release();

	SpriteAnimInfos.clear();

	if (DrawSpriteImage != nullptr)
	{
		DeleteObj(DrawSpriteImage);
	}
}

void CSpriteRenderer::InitializeSpriteRenderer(
	LPCTSTR		path, 
	float		spriteWidth, 
	float		spriteHeight, 
	float		drawWidth,
	float		drawHeight,
	bool		bUseTransparentBlt,
	DWORD       dwRop,
	COLORREF	crTransparent)

{
	DrawSpriteImage = new CBitmap(path);

	SpriteWidth = spriteWidth;
	SpriteHeight = spriteHeight;

	DrawWidth = drawWidth;
	DrawHeight = drawHeight;

	this->bUseTransparentBlt = bUseTransparentBlt;
	DWRop = dwRop;
	CRTransparent = crTransparent;
}

void CSpriteRenderer::RegisterSpriteAnimInfo(tstring animName, FSpriteAnimInfo newSpriteAnimInfo)
{
	if (SpriteAnimInfos.find(animName) == SpriteAnimInfos.end())
		SpriteAnimInfos.insert(make_pair(animName, newSpriteAnimInfo));
	else SpriteAnimInfos[animName] = newSpriteAnimInfo;
}

void CSpriteRenderer::ChangeAnimation(tstring newAnimationName, bool bChangeForce)
{
	// ���� �ִϸ��̼��� ����Ϸ��� �ϴ� ��� ���� ���
	if (!bChangeForce && (SpriteAnimName == newAnimationName)) return;

	// SpriteAnimInfos �� ����Ϸ��� �ִϸ��̼��� ��ϵǾ��ִ��� Ȯ���մϴ�.
	if (SpriteAnimInfos.find(newAnimationName) == SpriteAnimInfos.end()) return;

	SpriteAnimName = newAnimationName;
	SpriteAnimInfo = SpriteAnimInfos[newAnimationName];
}
