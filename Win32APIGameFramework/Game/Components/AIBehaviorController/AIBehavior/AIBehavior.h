#pragma once
#include "../../../../Framework/Base/Object/Object.h"
#include "../../../../Framework/Includes/Includes.h"

class CAIBehavior abstract : 
	public CObject
{
protected :
	// �ൿ�� ���� ���� �ð�
	float BehaviorBeginDelay;

	// �ൿ ���۰� ���� �����ϱ� ���� �ʵ��Դϴ�.
	bool bAllowBehaviorStart;
	/// - �ൿ ������ ����ϵ��� �� �������� ��Ÿ���ϴ�.

	bool bBehaviorFinished;
	/// - �ൿ�� �������� ��Ÿ���ϴ�.


public :
	virtual void Initialize() override;

	// �ൿ�� ���۵� �� ȣ��� �޼���
	virtual void StartBehaivor() PURE;

	// �ൿ ��ü�� �ʱ�ȭ �ϴ� �޼���
	virtual void InitializeBehaivor();

public :
	FORCEINLINE float GetBehaviorBeginDelay() const
	{ return BehaviorBeginDelay; }

	FORCEINLINE bool IsAllowedBehaviorStart() const
	{ return bAllowBehaviorStart; }

	FORCEINLINE bool IsBehaviorFinished() const
	{ return bBehaviorFinished; }


};

