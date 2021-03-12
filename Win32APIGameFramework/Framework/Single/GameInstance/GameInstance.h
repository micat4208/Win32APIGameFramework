#pragma once
#include "../../Base/Object/Object.h"
#include "../../Interfaces/ManagerClass.h"

class CGameInstance final :
    public CObject
{
public :
    CGameInstance();

private :
    // IManagerClass �������̽��� �����ϴ� ��ü���� �����մϴ�.
    map <string, IManagerClass*> ManagerClasses;

public :
    virtual void Initialize() override;
    virtual void Release() override;

private :
    template<typename ManagerClassType>
    FORCEINLINE void RegisterManagerClass()
    {
        // ��� ���踦 Ȯ���մϴ�.
        if (!IsA<IManagerClass, ManagerClassType>()) return;

        // SubManager ��ü�� �����մϴ�.
        IManagerClass* newSubManager = NewObj<ManagerClassType>();

        // �Ŵ��� ��ü�� �ʱ�ȭ�մϴ�.
        newSubManager->InitializeManagerClass();

        // map �� �߰��մϴ�.
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

