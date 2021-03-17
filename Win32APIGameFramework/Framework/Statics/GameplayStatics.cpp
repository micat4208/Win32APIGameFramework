#include "GameplayStatics.h"

FVector2 CGameplayStatics::GetMousePosition(bool translated)
{
    // 커서 위치를 저장할 변수
    POINT position;

    // 스크린 내에서 마우스 위치를 얻습니다.
    GetCursorPos(&position);
    if (!translated) return FVector2(position.x, position.y);

    // 창 내에서 마우스 위치를 얻습니다.
    ScreenToClient(Hwnd, &position);
    return FVector2(position.x, position.y);
}
