#pragma once
#include "../../Base/Object/Object.h"
#include "../../Interfaces/ManagerClass.h"

class CGameInstance final :
    public CObject
{
public :
    CGameInstance();

private :
    // IManagerClass 인터페이스를 구현하는 객체들을 저장합니다.
    map <string, IManagerClass*> ManagerClasses;

public :
    virtual void Initialize() override;
    virtual void Release() override;

private :
    template<typename ManagerClassType>
    FORCEINLINE void RegisterManagerClass()
    {
        // 상속 관계를 확인합니다.
        if (!IsA<IManagerClass, ManagerClassType>()) return;

        // SubManager 객체를 생성합니다.
        IManagerClass* newSubManager = NewObj<ManagerClassType>();

        // 매니저 객체를 초기화합니다.
        newSubManager->InitializeManagerClass();

        // map 에 추가합니다.
        ManagerClasses.insert(
            make_pair(typeid(ManagerClassType).name(), newSubManager) );
    }

public :
    template<typename ManagerClassType>
    FORCEINLINE ManagerClassType* GetManagerClass()
    {
        auto iter = ManagerClasses.find(
            string(typeid(ManagerClassType).name()));

        return (iter == ManagerClasses.end()) ?
            nullptr :
            Cast<ManagerClassType>(iter->second);
    }

};

