#include "ObjectPool.h"

IObjectPoolable* CObjectPool::RegisterRecyclableObject(IObjectPoolable* newRecyclableObject)
{
    PoolObjects.push_back(newRecyclableObject);
    return newRecyclableObject;
}

IObjectPoolable* CObjectPool::GetRecycledObject()
{
    return GetRecycledObject([](IObjectPoolable* obj) 
        { return obj->GetCanRecyclable(); });
}

IObjectPoolable* CObjectPool::GetRecycledObject(function<bool(IObjectPoolable* poolableObj)> pred)
{
    return nullptr;
}
