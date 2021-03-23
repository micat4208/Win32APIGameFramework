#include "Bitmap.h"

CBitmap::CBitmap()
{
    Hdc = MemDC = NULL;
    Bmp = OldBmp = NULL;
}

CBitmap::CBitmap(LPCTSTR path) : CBitmap()
{
    LoadBmp(path);
}

void CBitmap::Release()
{
    CObject::Release();

    DeleteObject(SelectObject(MemDC, OldBmp));
    DeleteDC(MemDC);
}

CBitmap* CBitmap::LoadBmp(LPCTSTR path)
{
    Hdc = ::GetDC(Hwnd);
    MemDC = CreateCompatibleDC(Hdc);

    Bmp = (HBITMAP)(LoadImage(NULL, path, IMAGE_BITMAP, 0, 0,
        LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    /// - LoadImage(hInstance, lpszName, uType, cx, cy, fuLoad) : 이미지를 로드합니다.
    /// - hInstance : 이미지 리소스를 가질 모듈의 핸들, 파일 경로를 대입하여 로드하는 경우 NULL 을 전달
    /// - lpszName : 파일 경로
    /// - uType : 읽고자 하는 타입을 지정
    /// - cx, cy : 아이콘이나 커서의 너비와 높이
    /// - fuLoad : 이미지를 읽어올 방법을 정의합니다.
    
    // 로드에 실패했는지 확인합니다.
    if (Bmp == NULL)
    {
        tstring msg = TEXT("파일을 로드하지 못했습니다.\n");
        msg += TEXT("경로 : ");
        msg += path;

        MessageBox(Hwnd, msg.c_str(), TEXT("BMP LOAD FAILED!"), MB_OK | MB_ICONERROR);

        return nullptr;
    }

    // 로드에 성공했다면
    BITMAP bitmapInfo;
    GetObject(Bmp, sizeof(bitmapInfo), &bitmapInfo);

    Size.X = bitmapInfo.bmWidth;
    Size.Y = bitmapInfo.bmHeight;

    OldBmp = (HBITMAP)SelectObject(MemDC, Bmp);
    ReleaseDC(Hwnd, Hdc);

    return this;
}
