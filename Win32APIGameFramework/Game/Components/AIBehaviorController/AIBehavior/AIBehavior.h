#pragma once
#include "../../../../Framework/Base/Object/Object.h"
#include "../../../../Framework/Includes/Includes.h"

class CAIBehavior abstract : 
	public CObject
{
public :
	// 이 행동을 관리하는 컴포넌트를 나타냅니다.
	class CAIBehaviorController* BehaviorController;

protected :
	// 행동이 시작된 시간 (StartBehaivor() 메서드가 호출된 시간)
	float BehaviorStartedTime;

	// 행동의 시작 지연 시간
	float BehaviorBeginDelay;

	// 행동 시작과 끝을 제어하기 위한 필드입니다.
	bool bAllowBehaviorStart;
	/// - 행동 시작을 허용하도록 할 것인지를 나타냅니다.

	bool bBehaviorFinished;
	/// - 행동이 끝났는지 나타냅니다.

private :
	// 행동이 시작되었음을 나타냅니다.
	bool bIsStarted;


public :
	virtual void Initialize() override;

	// 행동이 시작될 때 호출될 메서드
	virtual void StartBehaivor();

	// 행동이 실행중일 때 계속해서 호출되는 메서드
	virtual void BehaviorTick(float dt) PURE;

	// 행동 객체를 초기화 하는 메서드
	virtual void InitializeBehaivor();

public :
	FORCEINLINE float GetBehaviorBeginDelay() const
	{ return BehaviorBeginDelay; }

	FORCEINLINE bool IsAllowedBehaviorStart() const
	{ return bAllowBehaviorStart; }

	FORCEINLINE bool IsBehaviorFinished() const
	{ return bBehaviorFinished; }

	FORCEINLINE bool IsStarted() const
	{ return bIsStarted; }


};

