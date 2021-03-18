#include "CharacterRenderer.h"

#include "../../GameObjects/Characters/PlayerableCharacter/PlayerableCharacter.h"

#include "../../Components/PlayerAttack/PlayerAttack.h"


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
		auto playerAttack = Cast<CPlayerableCharacter>(GetOwner())->
			GetPlayerAttack();
		FVector2 direction = playerAttack->AttackDirection;

		// 선의 끝 위치
		FVector2 endPoint = (direction * playerAttack->Length) + GetOwner()->GetPosition();

		// 선을 그립니다.
		MoveToEx(hdc, 
			GetOwner()->GetPosition().X, 
			GetOwner()->GetPosition().Y, NULL);
		LineTo(hdc, endPoint.X, endPoint.Y);
	}
}
