#pragma once
#include "../../../../Framework/Base/Object/Object.h"
#include "../../../../Framework/Includes/Includes.h"

class CAIBehavior abstract : 
	public CObject
{
public :
	// �� �ൿ�� �����ϴ� ������Ʈ�� ��Ÿ���ϴ�.
	class CAIBehaviorController* BehaviorController;

protected :
	// �ൿ�� ���۵� �ð� (StartBehaivor() �޼��尡 ȣ��� �ð�)
	float BehaviorStartedTime;

	// �ൿ�� ���� ���� �ð�
	float BehaviorBeginDelay;

	// �ൿ ���۰� ���� �����ϱ� ���� �ʵ��Դϴ�.
	bool bAllowBehaviorStart;
	/// - �ൿ ������ ����ϵ��� �� �������� ��Ÿ���ϴ�.

	bool bBehaviorFinished;
	/// - �ൿ�� �������� ��Ÿ���ϴ�.

private :
	// �ൿ�� ���۵Ǿ����� ��Ÿ���ϴ�.
	bool bIsStarted;


public :
	virtual void Initialize() override;

	// �ൿ�� ���۵� �� ȣ��� �޼���
	virtual void StartBehaivor();

	// �ൿ�� �������� �� ����ؼ� ȣ��Ǵ� �޼���
	virtual void BehaviorTick(float dt) PURE;

	// �ൿ ��ü�� �ʱ�ȭ �ϴ� �޼���
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

