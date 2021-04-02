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
			// 이미지를 출력할 위치 핸들
			hdc,

			// 이미지를 그리기 시작할 위치
			drawCenter.X - (DrawWidth * 0.5f),
			drawCenter.Y - (DrawHeight * 0.5f),

			// 그려질 이미지 크기
			DrawWidth,
			DrawHeight,

			// 이미지 핸들
			DrawSpriteImage->GetDC(),

			// 원본 이미지의 자르기 시작할 X, Y 위치
			SpriteAnimInfo.SpriteIndex * SpriteWidth,
			SpriteAnimInfo.SpriteYIndex * SpriteHeight,

			// 원본 이미지에서 잘라낼 너비, 높이
			SpriteWidth,
			SpriteHeight,

			// 숨길 픽셀
			CRTransparent);
	}
	else
	{
		StretchBlt(
			// 이미지를 출력할 위치 핸들
			hdc,

			// 이미지를 그리기 시작할 위치
			drawCenter.X - (DrawWidth * 0.5f),
			drawCenter.Y - (DrawHeight * 0.5f),

			// 그려질 이미지 크기
			DrawWidth,
			DrawHeight,

			// 이미지 핸들
			DrawSpriteImage->GetDC(),

			// 원본 이미지의 자르기 시작할 X, Y 위치
			SpriteAnimInfo.SpriteIndex * SpriteWidth,
			SpriteAnimInfo.SpriteYIndex * SpriteHeight,

			// 원본 이미지에서 잘라낼 너비, 높이
			SpriteWidth,
			SpriteHeight,

			// 이미지 출력 방식
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
	// 같은 애니메이션을 재생하려고 하는 경우 실행 취소
	if (!bChangeForce && (SpriteAnimName == newAnimationName)) return;

	// SpriteAnimInfos 에 재생하려는 애니메이션이 등록되어있는지 확인합니다.
	if (SpriteAnimInfos.find(newAnimationName) == SpriteAnimInfos.end()) return;

	SpriteAnimName = newAnimationName;
	SpriteAnimInfo = SpriteAnimInfos[newAnimationName];
}
