#include "Scene.h"

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
}

void CScene::Initialize()
{ CObject::Initialize(); }

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
