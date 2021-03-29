#pragma once
#include "../Base/Object/Object.h"

#include "../Interfaces/ObjectPoolable.h"

// ������Ʈ Ǯ���� �����ϴ� Ŭ�����Դϴ�.
class CObjectPool final :
    public CObject
{
private :
    // Ǯ���� ��ü���� ������ vector
    vector<IObjectPoolable*> PoolObjects;

public :
    // Ǯ����ų ���ο� ��ü�� ����մϴ�.
    template<typename T>
    FORCEINLINE T* RegisterRecyclableObject(IObjectPoolable* newRecyclableObject)
    {
        PoolObjects.push_back(newRecyclableObject);
        return Cast<T>(newRecyclableObject);
    }
    
    // ��Ȱ��� ��ü�� ����ϴ�.
    IObjectPoolable* GetRecycledObject();

    // ��Ȱ��� ��ü�� ����ϴ�.
    // - pred : true ��� poolableObj �� ��ȯ�մϴ�.
    IObjectPoolable* GetRecycledObject(function<bool(IObjectPoolable* poolableObj)> pred);

public :
    virtual void Release() override;



};

