#pragma once
#include "../Base/Object/Object.h"

#include "../Interfaces/ObjectPoolable.h"

// 오브젝트 풀링을 수행하는 클래스입니다.
class CObjectPool final :
    public CObject
{
private :
    // 풀링할 객체들을 참조할 vector
    vector<IObjectPoolable*> PoolObjects;

public :
    // 풀링시킬 새로운 객체를 등록합니다.
    IObjectPoolable* RegisterRecyclableObject(IObjectPoolable* newRecyclableObject);
    
    // 재활용된 객체를 얻습니다.
    IObjectPoolable* GetRecycledObject();

    // 재활용된 객체를 얻습니다.
    // - pred : true 라면 poolableObj 를 반환합니다.
    IObjectPoolable* GetRecycledObject(function<bool(IObjectPoolable* poolableObj)> pred);




};

