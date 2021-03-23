#pragma once

#include "../../Includes/Includes.h"

// Ŭ���� : C
// ����ü : F
// �������̽� : I

#ifndef COBJECT_RELEASE
#define COBJECT_RELEASE
#define DeleteObj(var) var->Release(); delete var; var = nullptr

#endif

// ��� Ŭ������ ��� ������ �� Ŭ����
class CObject
{
public :
	CObject();
	virtual ~CObject();

	virtual void Initialize();
	virtual void Release();


	void Test(class CCollision* other);

public :
	virtual tstring ToString() const;
};

template<typename T>
T* NewObj()
{
	CObject* newObj = new T();
	newObj->Initialize();

	return Cast<T>(newObj);
}

