#pragma once

#include "../Includes/Includes.h"

// SubManager Ŭ������ ��� ����
interface IManagerClass
{
	// �Ŵ��� ��ü�� ��ϵ� �� ȣ��� �޼���
	virtual void InitializeManagerClass() PURE;

	// �Ŵ��� ��ü�� �Ҹ�� �� ȣ��� �޼���
	virtual void ReleaseManagerClass() PURE;

	virtual ~IManagerClass() {}
};