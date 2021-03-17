#pragma once
#include "../GameObject/GameObject.h"

class CScene :
    public CObject
{
private :
    // ������ ���Ǵ� ������Ʈ�� ������ ����Ʈ
    list<CGameObject*> UsedGameObjectList;

    // ������ ������Ʈ�� ������ ����Ʈ
    list<CGameObject*> CreatedGameObjectList;

    // ���ŵ� ������Ʈ�� ������ ����Ʈ
    list<CGameObject*> DestroyedGameObjectList;

    // �߰��� RenderComponent �� ������ ����Ʈ
    list<class CRenderComponent*> CreatedRenderComponents;

    // ���� �׸��� �۾��� ����Ǵ� RenderComponent �� ������ ����Ʈ
    list<class CRenderComponent*> UsedRenderComponents;

    class CBitmap* Erase, * BackBuffer;

public :
    // UsedRenderComponents �� �߰��� ��ҵ��� ������ �ʿ����� ��Ÿ���ϴ�.
    bool bNeedSort;


public :
    virtual void Initialize() override;
    virtual void Tick(float dt);
    virtual void Render(HDC hdc);
    virtual void Release() override;


public :
    template<typename T>
    FORCEINLINE T* NewObject(
        tstring objName = tstring(TEXT("GameObject")))
    {
        // ��� ���踦 Ȯ���մϴ�.
        if (!IsA<CGameObject, T>()) return nullptr;

        // ������Ʈ ����
        CGameObject* newObj = NewObj<T>();
        
        // ������ ������Ʈ�� �����ϴ� ���� �ڽ����� �����մϴ�.
        newObj->OwnerScene = this;

        // ������ ������Ʈ �̸��� �����մϴ�.
        newObj->SetObjectName(objName);

        CreatedGameObjectList.push_back(newObj);

        return Cast<T>(newObj);
    }


    // ���� �߰��� ������Ʈ�� objName �� ��ġ�ϴ� �̸��� ���� ������Ʈ �ϳ��� ã���ϴ�.
    CObject* FindObject(tstring objName);

    // ���� �߰��� ������Ʈ�� objName �� ��ġ�ϴ� ������Ʈ���� ã���ϴ�.
    /// - return : ã�� ������Ʈ�� �����ϴ� ��� true ����
    /// - objName : ã�� ������Ʈ�� �̸�
    /// - outFindedObjects : ã�� ������Ʈ�� ������ vector
    bool FindObjects(tstring objName, vector<CGameObject*>& outFindedObjects);

    // ������Ʈ�� �����մϴ�.
    void Destroy(CGameObject* obj);

    FORCEINLINE void RegisterNewRenderComponent(
        class CRenderComponent* newRenderComponent)
    { CreatedRenderComponents.push_back(newRenderComponent); }


};

