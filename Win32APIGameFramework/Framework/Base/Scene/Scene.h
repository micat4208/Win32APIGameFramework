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


};

