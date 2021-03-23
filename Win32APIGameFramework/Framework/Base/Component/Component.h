#pragma once
#include "../Object/Object.h"
#include "../../Structrues/Vector2/Vector2.h"

// ��� ��ü�� ����� ��Ÿ�� �� ���Ǵ� Ŭ����
class CComponent abstract :
    public CObject
{
protected :
    // �ش� ������Ʈ�� �����ϴ� ������Ʈ�� ��Ÿ���ϴ�.
    class CGameObject* Owner;

public :
    bool bBeDestroy;

    // Tick() �޼��带 ����ϵ��� �� �������� �����մϴ�.
    bool bCanEverTick;

    // Start() �޼��尡 ȣ��Ǿ����� Ȯ���� ����
    bool bIsStarted;

public :
    CComponent();

public :
    virtual void Start();
    virtual void Tick(float dt);

public :
    FORCEINLINE void SetOwner(class CGameObject* owner)
    { Owner = owner; }

    FORCEINLINE class CGameObject* GetOwner() const
    { return Owner; }
};

