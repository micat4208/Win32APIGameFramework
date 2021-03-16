#include "Scene.h"
#include "../../Bitmap/Bitmap.h"

void CScene::Initialize()
{ 
    CObject::Initialize(); 

    Erase = NewObj<CBitmap>();
    Erase->LoadBmp(TEXT("Resources/Back/Back.bmp"));

    BackBuffer = NewObj<CBitmap>();
    BackBuffer->LoadBmp(TEXT("Resources/Back/Back.bmp"));

}

void CScene::Tick(float dt)
{
    // �߰��� ���� ������Ʈ�� �����ϴ� ���
    if (CreatedGameObjectList.size() > 0)
    {
        for (auto gameObj : CreatedGameObjectList)
            UsedGameObjectList.push_back(gameObj);
        CreatedGameObjectList.clear();
    }
    
    // ������ ���� ������Ʈ�� �����ϴ� ���
    if (DestroyedGameObjectList.size() > 0)
    {
        for (auto gameObj : DestroyedGameObjectList)
        {
            // �����Ϸ��� ���� ������Ʈ�� UsedGameObjectList ���� ����
            UsedGameObjectList.remove(gameObj);

            // �޸� ����
            DeleteObj(gameObj);
        }
        DestroyedGameObjectList.clear();
    }

    // ���� ������� ���� ������Ʈ���� Tick() �޼��� ȣ��
    for (auto gameObj : UsedGameObjectList)
    {
        // ���� ����̶�� Tick() �޼��带 ȣ������ �ʵ��� �մϴ�.
        if (gameObj->bBeDestroy) continue;

        // Start() �޼��尡 ȣ����� �ʾҴٸ�
        if (!gameObj->bIsStarted)
            // Start() �޼��� ȣ��
            gameObj->Start();

        // Tick() �޼��带 ����Ѵٸ� 
        if (gameObj->bCanEverTick)
            // Tick() �޼��� ȣ��
            gameObj->Tick(dt);
    }

}

void CScene::Render(HDC hdc)
{
    BitBlt(BackBuffer->GetDC(), 0, 0, WND_WIDTH, WND_HEIGHT, Erase->GetDC(), 0, 0, SRCCOPY);

    Rectangle(BackBuffer->GetDC(), 50, 50, 100, 100);

    BitBlt(hdc, 0, 0, WND_WIDTH, WND_HEIGHT, BackBuffer->GetDC(), 0, 0, SRCCOPY);
}

void CScene::Release()
{
    CObject::Release();

    // �߰��Ϸ��� ������Ʈ�� �����ϴ� ���
    if (CreatedGameObjectList.size() != 0)
    {
        for (auto iter = CreatedGameObjectList.begin();
            iter != CreatedGameObjectList.end(); ++iter)
        {
            DeleteObj((*iter));
        }

        CreatedGameObjectList.clear();
    }

    // �߰��� ������Ʈ ����
    for (auto usedObj : UsedGameObjectList)
    {
        DeleteObj(usedObj);
    }
    UsedGameObjectList.clear();

    // Bitmap ��ü ����
    DeleteObj(Erase);
    DeleteObj(BackBuffer);
}

CObject* CScene::FindObject(tstring objName)
{
    for (auto iter = UsedGameObjectList.begin();
        iter != UsedGameObjectList.end(); ++iter)
    {
        if ((*iter)->bBeDestroy) continue;
        else if (!(*iter)->bIsStarted) continue;


        if ((*iter)->GetObjectName() == objName)
            return (*iter);
    }

    return nullptr;
}

bool CScene::FindObjects(tstring objName, vector<CGameObject*>& outFindedObjects)
{
    bool finded = false;

    for (auto obj : UsedGameObjectList)
    {
        if (obj->bBeDestroy) continue;
        else if (!obj->bIsStarted) continue;

        if (obj->GetObjectName() == objName)
        {
            finded = true;
            outFindedObjects.push_back(obj);
        }
    }

    return finded;
}

void CScene::Destroy(CGameObject* obj)
{
    // ���� ����̶�� ���� ���
    if (obj->bBeDestroy) return;

    obj->bBeDestroy = true;
    obj->OnDestory();
    DestroyedGameObjectList.push_back(obj);
}
