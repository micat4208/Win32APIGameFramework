#pragma once

#define _USE_MATH_DEFINES

#include "../../Includes/Includes.h"
#include <cmath>

#define PI		M_PI
#define SMALLNUMBER		(1.e-8f)

struct FMath
{
	// 정수 형식의 난수를 반환하는 함수
	static FORCEINLINE __int32 Rand()			
	{ return rand(); }

	// 실수 형식의 난수를 반환하는 함수
	static FORCEINLINE float FRand()			
	{ return rand() / (float)RAND_MAX; }

	// Boolean 형식의 난수를 반환하는 함수
	static FORCEINLINE bool BRand()			
	{ return (rand() % 2 == 1) ? true : false; }


	// 범위 내의 정수 형식의 난수를 반환하는 함수
	static FORCEINLINE __int32 RandRange(__int32 min, __int32 max)
	{ return (Rand() % ((max + 1) - min)) + min; }
	
	// 범위 내의 실수 형식의 난수를 반환하는 함수
	static FORCEINLINE float FRandRange(float min, float max)
	{ return (min + (max - min) * FRand()); }

	// 절대값을 반환하는 함수
	static FORCEINLINE __int32 Abs(__int32 i)
	{ return abs(i); }
	static FORCEINLINE float Abs(float f)
	{ return fabs(f); }

	// 실수 a, b 가 서로 비슷한 값임을 확인하는 함수
	static FORCEINLINE bool Approximately(float a, float b, 
		float errorTolenance = SMALLNUMBER)
	{ return Abs(a - b) <= errorTolenance; }

	// value 의 값을 min 과 max 사이의 값으로 변환한 뒤 반환합니다.
	static FORCEINLINE __int32 Clamp(__int32 value, __int32 _min, __int32 _max)
	{ return min(_max, max(value, _min)); }
	static FORCEINLINE float Clamp(float value, float _min, float _max)
	{ return min(_max, max(value, _min)); }

	// value 의 값을 min 과 max 사이의 값인지 확인합니다.
	static FORCEINLINE bool IsIn(__int32 value, __int32 min, __int32 max)
	{ return (value >= min && value <= max); }

	static FORCEINLINE bool IsIn(float value, float min, float max)
	{ return (value >= min && value <= max); }
};

