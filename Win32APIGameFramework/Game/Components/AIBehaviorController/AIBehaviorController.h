#pragma once

#include "../../../Framework/Base/Component/Component.h"
#include "AIBehavior/AIBehavior.h"

// AI 행동 객체를 관리할 클래스입니다.
class CAIBehaviorController final :
    public CComponent
{
private :
    // 행동 객체들을 나타냅니다.
    vector<CAIBehavior*> Behaviors;

    // 다음으로 실행할 행동 인덱스를 나타냅니다.
    int NextBehaviorIndex;

    // 행동 관리가 시작 되었는지를 나타냅니다.
    bool bBehaviorControlStarted;

    // 마지막으로 행동이 시작된 시간을 나타냅니다.
    float LastBehaviorStartedTime;

public :
    virtual void Initialize() override;
    virtual void Tick(float dt) override;
    virtual void Release() override;

public :
    template<typename BehaviorType>
    FORCEINLINE BehaviorType * RegisterBehavior()
    {
        // CAIBehavior 와 BehaviorType 형식이 상속 관계에 속하지 않는 경우 행동 객체 등록을 취소합니다.
        if (!IsA(CAIBehavior, BehaviorType)) return nullptr;

        // 행동 객체 생성
        BehaviorType * newBehavior = NewObj<BehaviorType>();

        // 행동 객체 등록
        Behaviors.push_back(newBehavior);

        // 행동 객체 초기화
        Cast<CAIBehavior>(newBehavior)->InitializeBehaivor();

        return newBehavior;
    }

    // 행동 관리를 시작합니다.
    void StartBehaviorControl();

private :
    // 행동 객체들을 관리합니다.
    void BehaviorControl();



};

