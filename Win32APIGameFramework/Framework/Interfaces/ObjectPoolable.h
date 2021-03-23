#pragma once
#include "../Includes/Includes.h"

// Ǯ����ų ��ü���� �����ؾ� �ϴ� �������̽� Ŭ�����Դϴ�.
interface IObjectPoolable
{
	// ���� ���� ���¿� ���� ������ �����ڸ� �����մϴ�.
	virtual void SetCanRecyclable(bool bCanRecyclable) PURE;
	virtual bool GetCanRecyclable() const PURE;

	// ��Ȱ���� �Ǵ� ������ ȣ��Ǵ� �޼���
	virtual void OnRecycleStarted() PURE;

	virtual ~IObjectPoolable() {}
};
