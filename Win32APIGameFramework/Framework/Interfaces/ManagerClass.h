#pragma once

#include "../Includes/Includes.h"

// SubManager 클래스의 기반 형태
interface IManagerClass
{
	// 매니저 객체가 등록될 때 호출될 메서드
	virtual void InitializeManagerClass() PURE;

	// 매니저 객체가 소멸될 때 호출될 메서드
	virtual void ReleaseManagerClass() PURE;

	virtual ~IManagerClass() {}
};