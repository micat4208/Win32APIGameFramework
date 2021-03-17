#include "CharacterRenderer.h"

#include "../../../Framework/Statics/GameplayStatics.h"

#include "../../GameObjects/Characters/Character.h"


CCharacterRenderer::CCharacterRenderer()
{
	Radius = 30.0f;
	bDrawLine = false;
}

void CCharacterRenderer::Render(HDC hdc)
{
	FVector2 center = GetOwner()->GetPosition();

	Ellipse(hdc,
		center.X - Radius,
		center.Y - Radius,
		center.X + Radius,
		center.Y + Radius);

	if (bDrawLine)
	{
		// 마우스 위치를 얻습니다.
		FVector2 mousePosition = CGameplayStatics::GetMousePosition();

		FVector2 direction = FVector2::Direction(
			GetOwner()->GetPosition(), mousePosition);

		LOG(direction.ToString().c_str());

		// 그릴 선의 길이를 설정합니다.
		float length = 30.0f;
		
		// 선의 끝 위치
		FVector2 endPoint = (direction * length) + GetOwner()->GetPosition();

		// 선을 그립니다.
		MoveToEx(hdc, GetOwner()->GetPosition().X, GetOwner()->GetPosition().Y, NULL);
		LineTo(hdc, endPoint.X, endPoint.Y);
	}
}
