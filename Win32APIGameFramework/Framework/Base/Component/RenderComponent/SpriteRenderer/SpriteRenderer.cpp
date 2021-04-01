#include "SpriteRenderer.h"

#include "Framework/Statics/GameplayStatics.h"

void CSpriteRenderer::Initialize()
{
	CRenderComponent::Initialize();
	DrawSpriteImage = nullptr;
	SpriteDelay = 0;
	LastSpriteChangedTime = CGameplayStatics::GetTime();
}

void CSpriteRenderer::Render(HDC hdc)
{
	if (DrawSpriteImage == nullptr) return;

	// TODO
}

void CSpriteRenderer::Release()
{
	CRenderComponent::Release();

	if (DrawSpriteImage != nullptr)
	{
		DeleteObj(DrawSpriteImage);
	}
}

void CSpriteRenderer::InitializeSpriteRenderer(LPCTSTR path, float spriteDelay)
{
	DrawSpriteImage = new CBitmap(path);
	SpriteDelay = spriteDelay;
}
