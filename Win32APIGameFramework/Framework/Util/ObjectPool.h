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
    IObjectPoolable* RegisterRecyclableObject(IObjectPoolable* newRecyclableObject);
    
    // ��Ȱ��� ��ü�� ����ϴ�.
    IObjectPoolable* GetRecycledObject();

    // ��Ȱ��� ��ü�� ����ϴ�.
    // - pred : true ��� poolableObj �� ��ȯ�մϴ�.
    IObjectPoolable* GetRecycledObject(function<bool(IObjectPoolable* poolableObj)> pred);




};

