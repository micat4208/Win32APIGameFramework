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
		// ���콺 ��ġ�� ����ϴ�.
		FVector2 mousePosition = CGameplayStatics::GetMousePosition();

		FVector2 direction = FVector2::Direction(
			GetOwner()->GetPosition(), mousePosition);

		LOG(direction.ToString().c_str());

		// �׸� ���� ���̸� �����մϴ�.
		float length = 30.0f;
		
		// ���� �� ��ġ
		FVector2 endPoint = (direction * length) + GetOwner()->GetPosition();

		// ���� �׸��ϴ�.
		MoveToEx(hdc, GetOwner()->GetPosition().X, GetOwner()->GetPosition().Y, NULL);
		LineTo(hdc, endPoint.X, endPoint.Y);
	}
}
