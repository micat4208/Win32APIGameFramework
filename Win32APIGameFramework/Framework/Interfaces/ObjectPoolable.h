#pragma once
#include "../Includes/Includes.h"

// 풀링시킬 객체에서 구현해야 하는 인터페이스 클래스입니다.
interface IObjectPoolable
{
	// 재사용 가능 상태에 대한 접근자 설정자를 구성합니다.
	virtual void SetCanRecyclable(bool bCanRecyclable) PURE;
	virtual bool GetCanRecyclable() const PURE;

	// 재활용이 되는 시점에 호출되는 메서드
	virtual void OnRecycleStarted() PURE;

	virtual ~IObjectPoolable() {}
};
