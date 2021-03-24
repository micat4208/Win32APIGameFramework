#include "ObjectPool.h"

IObjectPoolable* CObjectPool::GetRecycledObject()
{
    return GetRecycledObject([](IObjectPoolable* obj) 
        { return obj->GetCanRecyclable(); });
}

IObjectPoolable* CObjectPool::GetRecycledObject(
    function<bool(IObjectPoolable* poolableObj)> pred)
{
    // ����� ������ 0 �̶�� nullptr ����
    if (PoolObjects.size() == 0) return nullptr;

    for (auto obj : PoolObjects)
    {
        if (pred(obj))
        {
            obj->SetCanRecyclable(false);
            obj->OnRecycleStarted();
            return obj;
        }
    }

    return nullptr;
}

void CObjectPool::Release()
{
    __super::Release();

    PoolObjects.clear();
}
