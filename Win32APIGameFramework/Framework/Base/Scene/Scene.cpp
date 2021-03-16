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
    // 추가할 게임 오브젝트가 존재하는 경우
    if (CreatedGameObjectList.size() > 0)
    {
        for (auto gameObj : CreatedGameObjectList)
            UsedGameObjectList.push_back(gameObj);
        CreatedGameObjectList.clear();
    }
    
    // 제거할 게임 오브젝트가 존재하는 경우
    if (DestroyedGameObjectList.size() > 0)
    {
        for (auto gameObj : DestroyedGameObjectList)
        {
            // 제거하려는 게임 오브젝트를 UsedGameObjectList 에서 제거
            UsedGameObjectList.remove(gameObj);

            // 메모리 해제
            DeleteObj(gameObj);
        }
        DestroyedGameObjectList.clear();
    }

    // 실제 사용중인 게임 오브젝트들의 Tick() 메서드 호출
    for (auto gameObj : UsedGameObjectList)
    {
        // 삭제 대상이라면 Tick() 메서드를 호출하지 않도록 합니다.
        if (gameObj->bBeDestroy) continue;

        // Start() 메서드가 호출되지 않았다면
        if (!gameObj->bIsStarted)
            // Start() 메서드 호출
            gameObj->Start();

        // Tick() 메서드를 사용한다면 
        if (gameObj->bCanEverTick)
            // Tick() 메서드 호출
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

    // 추가하려는 오브젝트가 존재하는 경우
    if (CreatedGameObjectList.size() != 0)
    {
        for (auto iter = CreatedGameObjectList.begin();
            iter != CreatedGameObjectList.end(); ++iter)
        {
            DeleteObj((*iter));
        }

        CreatedGameObjectList.clear();
    }

    // 추가된 오브젝트 해제
    for (auto usedObj : UsedGameObjectList)
    {
        DeleteObj(usedObj);
    }
    UsedGameObjectList.clear();

    // Bitmap 객체 해제
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
    // 제거 대상이라면 실행 취소
    if (obj->bBeDestroy) return;

    obj->bBeDestroy = true;
    obj->OnDestory();
    DestroyedGameObjectList.push_back(obj);
}
