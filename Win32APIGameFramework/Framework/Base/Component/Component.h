#pragma once
#include "../Object/Object.h"
#include "../../Structrues/Vector2/Vector2.h"

// 어떠한 물체의 기능을 나타낼 때 사용되는 클래스
class CComponent abstract :
    public CObject
{
protected :
    // 해당 컴포넌트를 소유하는 오브젝트를 나타냅니다.
    class CGameObject* Owner;

public :
    bool bBeDestroy;

    // Tick() 메서드를 사용하도록 할 것인지를 결정합니다.
    bool bCanEverTick;

    // Start() 메서드가 호출되었는지 확인할 변수
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

