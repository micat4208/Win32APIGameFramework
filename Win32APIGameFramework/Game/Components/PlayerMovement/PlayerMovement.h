#pragma once
#include "Framework/Base/Component/Component.h"

class CPlayerMovement :
    public CComponent
{
private :
    // ���� ��
    float JumpPower;

    // �ִ� �ӷ�
    float MaxYVelocity;

    // Y �ӷ�
    float YVelocity;

public :
    virtual void Initialize() override;
    virtual void Tick(float dt) override;

public :
    // ȣ��Ǿ��� ��� �����մϴ�.
    void Jump();
    
private :
    // �������� �̵��� �����մϴ�.
    void FallDown(float dt);



};

