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
    /// - LoadImage(hInstance, lpszName, uType, cx, cy, fuLoad) : �̹����� �ε��մϴ�.
    /// - hInstance : �̹��� ���ҽ��� ���� ����� �ڵ�, ���� ��θ� �����Ͽ� �ε��ϴ� ��� NULL �� ����
    /// - lpszName : ���� ���
    /// - uType : �а��� �ϴ� Ÿ���� ����
    /// - cx, cy : �������̳� Ŀ���� �ʺ�� ����
    /// - fuLoad : �̹����� �о�� ����� �����մϴ�.
    
    // �ε忡 �����ߴ��� Ȯ���մϴ�.
    if (Bmp == NULL)
    {
        tstring msg = TEXT("������ �ε����� ���߽��ϴ�.\n");
        msg += TEXT("��� : ");
        msg += path;

        MessageBox(Hwnd, msg.c_str(), TEXT("BMP LOAD FAILED!"), MB_OK | MB_ICONERROR);

        return nullptr;
    }

    // �ε忡 �����ߴٸ�
    BITMAP bitmapInfo;
    GetObject(Bmp, sizeof(bitmapInfo), &bitmapInfo);

    Size.X = bitmapInfo.bmWidth;
    Size.Y = bitmapInfo.bmHeight;

    OldBmp = (HBITMAP)SelectObject(MemDC, Bmp);
    ReleaseDC(Hwnd, Hdc);

    return this;
}
