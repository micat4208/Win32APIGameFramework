#pragma once
#include "../../Base/Object/Object.h"
#include "../../Interfaces/ManagerClass.h"

class CGameInstance final :
    public CObject
{
public :
    CGameInstance();

private :
    HDC Hdc;

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


        // map �� �߰��մϴ�.
        ManagerClasses.insert(
            make_pair(typeid(ManagerClassType).name(), newSubManager) );

        // �Ŵ��� ��ü�� �ʱ�ȭ�մϴ�.
        newSubManager->InitializeManagerClass();
    }

public :
    template<typename ManagerClassType>
    FORCEINLINE ManagerClassType* GetManagerClass()
    {
        return Cast<ManagerClassType>(ManagerClasses[string(typeid(ManagerClassType).name())]);
        auto iter = ManagerClasses.find(
            string(typeid(ManagerClassType).name()));

        return (iter == ManagerClasses.end()) ?
            nullptr :
            Cast<ManagerClassType>(iter->second);
    }

public :
    FORCEINLINE HDC& GetDC()
    { return Hdc; }

};

