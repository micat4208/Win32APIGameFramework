#pragma once

#include "../../../Framework/Base/Component/Component.h"
#include "AIBehavior/AIBehavior.h"

// AI �ൿ ��ü�� ������ Ŭ�����Դϴ�.
class CAIBehaviorController final :
    public CComponent
{
private :
    // �ൿ ��ü���� ��Ÿ���ϴ�.
    vector<CAIBehavior*> Behaviors;

    // �������� ������ �ൿ �ε����� ��Ÿ���ϴ�.
    int NextBehaviorIndex;

    // �ൿ ������ ���� �Ǿ������� ��Ÿ���ϴ�.
    bool bBehaviorControlStarted;

    // ���������� �ൿ�� ���۵� �ð��� ��Ÿ���ϴ�.
    float LastBehaviorStartedTime;

public :
    virtual void Initialize() override;
    virtual void Tick(float dt) override;
    virtual void Release() override;

public :
    template<typename BehaviorType>
    FORCEINLINE BehaviorType * RegisterBehavior()
    {
        // CAIBehavior �� BehaviorType ������ ��� ���迡 ������ �ʴ� ��� �ൿ ��ü ����� ����մϴ�.
        if (!IsA(CAIBehavior, BehaviorType)) return nullptr;

        // �ൿ ��ü ����
        BehaviorType * newBehavior = NewObj<BehaviorType>();

        // �ൿ ��ü ���
        Behaviors.push_back(newBehavior);

        // �ൿ ��ü �ʱ�ȭ
        Cast<CAIBehavior>(newBehavior)->InitializeBehaivor();

        return newBehavior;
    }

    // �ൿ ������ �����մϴ�.
    void StartBehaviorControl();

private :
    // �ൿ ��ü���� �����մϴ�.
    void BehaviorControl();



};

