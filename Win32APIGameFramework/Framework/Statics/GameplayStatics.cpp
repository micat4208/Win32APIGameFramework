#include "GameplayStatics.h"

float CGameplayStatics::GetTime()
{
    return (GetTickCount64() - GameStartTime) * 0.001f;
}

FVector2 CGameplayStatics::GetMousePosition(bool translated)
{
    // Ŀ�� ��ġ�� ������ ����
    POINT position;

    // ��ũ�� ������ ���콺 ��ġ�� ����ϴ�.
    GetCursorPos(&position);
    if (!translated) return FVector2(position.x, position.y);

    // â ������ ���콺 ��ġ�� ����ϴ�.
    ScreenToClient(Hwnd, &position);
    return FVector2(position.x, position.y);
}
