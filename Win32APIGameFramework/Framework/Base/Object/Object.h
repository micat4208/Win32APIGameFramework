#pragma once

#include "../../Includes/Includes.h"

// 클래스 : C
// 구조체 : F
// 인터페이스 : I

#ifndef COBJECT_RELEASE
#define COBJECT_RELEASE
#define DeleteObj(var) var->Release(); delete var; var = nullptr

#endif

// 모든 클래스의 기반 형식이 될 클래스
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

