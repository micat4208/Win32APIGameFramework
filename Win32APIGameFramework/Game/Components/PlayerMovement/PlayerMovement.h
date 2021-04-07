#pragma once
#include "Framework/Base/Component/Component.h"

class CPlayerMovement :
    public CComponent
{
private :
    // 점프 힘
    float JumpPower;

    // 최대 속력
    float MaxYVelocity;

    // Y 속력
    float YVelocity;

public :
    virtual void Initialize() override;
    virtual void Tick(float dt) override;

public :
    // 호출되었을 경우 점프합니다.
    void Jump();
    
private :
    // 떨어지는 이동을 구현합니다.
    void FallDown(float dt);



};

