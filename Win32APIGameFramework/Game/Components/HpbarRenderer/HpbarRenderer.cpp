#include "HpbarRenderer.h"

#include "../../GameObjects/Characters/Character.h"

void CHpbarRenderer::Initialize()
{
	__super::Initialize();

	OwnerCharacter = Cast<CCharacter>(GetOwner());
}

void CHpbarRenderer::Start()
{
	__super::Start();
	bIsPlayer = OwnerCharacter->HasTag(TAG_PLAYER_CHARACTER);

	const COLORREF playerColor = RGB(50, 150, 255);
	const COLORREF enemyColor = RGB(255, 50, 110);

	MyBrush = CreateSolidBrush(bIsPlayer ? playerColor : enemyColor);
	MyPen = CreatePen(PS_SOLID, 1, bIsPlayer ? playerColor : enemyColor);
}

void CHpbarRenderer::Render(HDC hdc)
{
	FVector2 hpbarCenterPosition = OwnerCharacter->GetPosition();
	hpbarCenterPosition += FVector2::UpVector() * 40.0f;

	const int hpbarHalfWidth = 20;
	const int hpbarHalfHeight = 3;

	Rectangle(hdc,
		hpbarCenterPosition.X - hpbarHalfWidth,
		hpbarCenterPosition.Y - hpbarHalfHeight,
		hpbarCenterPosition.X + hpbarHalfWidth,
		hpbarCenterPosition.Y + hpbarHalfHeight);

	OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);
	OldPen = (HPEN)SelectObject(hdc, MyPen);

	Rectangle(hdc,
		hpbarCenterPosition.X - hpbarHalfWidth,
		hpbarCenterPosition.Y - hpbarHalfHeight,
		(hpbarCenterPosition.X - hpbarHalfWidth) + 
		((OwnerCharacter->GetHp() / OwnerCharacter->GetMaxHp()) * (hpbarHalfWidth * 2)),
		hpbarCenterPosition.Y + hpbarHalfHeight);

	SelectObject(hdc, OldBrush);
	SelectObject(hdc, OldPen);
	
}

void CHpbarRenderer::Release()
{
	__super::Release();

	DeleteObject(MyBrush);
	DeleteObject(MyPen);
}
