#pragma once
#include "../GameObject/GameObject.h"

class CScene :
    public CObject
{
private :
    // 씬에서 사용되는 오브젝트를 저장할 리스트
    list<CGameObject*> UsedGameObjectList;

    // 생성된 오브젝트를 저장할 리스트
    list<CGameObject*> CreatedGameObjectList;

    // 제거될 오브젝트를 저장할 리스트
    list<CGameObject*> DestroyedGameObjectList;

    // 추가될 RenderComponent 를 저장할 리스트
    list<class CRenderComponent*> CreatedRenderComponents;

    // 실제 그리기 작업이 진행되는 RenderComponent 를 저장할 리스트
    list<class CRenderComponent*> UsedRenderComponents;

    class CBitmap* Erase, * BackBuffer;

public :
    // UsedRenderComponents 에 추가된 요소들의 정렬이 필요함을 나타냅니다.
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
        // 상속 관계를 확인합니다.
        if (!IsA<CGameObject, T>()) return nullptr;

        // 오브젝트 생성
        CGameObject* newObj = NewObj<T>();
        
        // 생성된 오브젝트를 소유하는 씬을 자신으로 설정합니다.
        newObj->OwnerScene = this;

        // 생성된 오브젝트 이름을 설정합니다.
        newObj->SetObjectName(objName);

        CreatedGameObjectList.push_back(newObj);

        return Cast<T>(newObj);
    }


    // 씬에 추가된 오브젝트중 objName 와 일치하는 이름을 가진 오브젝트 하나를 찾습니다.
    CObject* FindObject(tstring objName);

    // 씬에 추가된 오브젝트중 objName 과 일치하는 오브젝트들을 찾습니다.
    /// - return : 찾은 오브젝트가 존재하는 경우 true 리턴
    /// - objName : 찾을 오브젝트의 이름
    /// - outFindedObjects : 찾은 오브젝트를 저장할 vector
    bool FindObjects(tstring objName, vector<CGameObject*>& outFindedObjects);

    // 오브젝트를 제거합니다.
    void Destroy(CGameObject* obj);

    FORCEINLINE void RegisterNewRenderComponent(
        class CRenderComponent* newRenderComponent)
    { CreatedRenderComponents.push_back(newRenderComponent); }


};

