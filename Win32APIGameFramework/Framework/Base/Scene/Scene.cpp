#include "Scene.h"

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
}

void CScene::Initialize()
{ CObject::Initialize(); }

void CScene::Tick(float dt)
{
    
}

void CScene::Render(HDC hdc)
{
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
