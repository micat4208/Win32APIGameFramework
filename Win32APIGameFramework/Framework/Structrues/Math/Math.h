#pragma once

#define _USE_MATH_DEFINES

#include "../../Includes/Includes.h"
#include <cmath>

#define PI		M_PI
#define SMALLNUMBER		(1.e-8f)

struct FMath
{
	// ���� ������ ������ ��ȯ�ϴ� �Լ�
	static FORCEINLINE __int32 Rand()			
	{ return rand(); }

	// �Ǽ� ������ ������ ��ȯ�ϴ� �Լ�
	static FORCEINLINE float FRand()			
	{ return rand() / (float)RAND_MAX; }

	// Boolean ������ ������ ��ȯ�ϴ� �Լ�
	static FORCEINLINE bool BRand()			
	{ return (rand() % 2 == 1) ? true : false; }


	// ���� ���� ���� ������ ������ ��ȯ�ϴ� �Լ�
	static FORCEINLINE __int32 RandRange(__int32 min, __int32 max)
	{ return (Rand() % ((max + 1) - min)) + min; }
	
	// ���� ���� �Ǽ� ������ ������ ��ȯ�ϴ� �Լ�
	static FORCEINLINE float FRandRange(float min, float max)
	{ return (min + (max - min) * FRand()); }

	// ���밪�� ��ȯ�ϴ� �Լ�
	static FORCEINLINE __int32 Abs(__int32 i)
	{ return abs(i); }
	static FORCEINLINE float Abs(float f)
	{ return fabs(f); }

	// �Ǽ� a, b �� ���� ����� ������ Ȯ���ϴ� �Լ�
	static FORCEINLINE bool Approximately(float a, float b, 
		float errorTolenance = SMALLNUMBER)
	{ return Abs(a - b) <= errorTolenance; }

	// value �� ���� min �� max ������ ������ ��ȯ�� �� ��ȯ�մϴ�.
	static FORCEINLINE __int32 Clamp(__int32 value, __int32 _min, __int32 _max)
	{ return min(_max, max(value, _min)); }
	static FORCEINLINE float Clamp(float value, float _min, float _max)
	{ return min(_max, max(value, _min)); }

	// value �� ���� min �� max ������ ������ Ȯ���մϴ�.
	static FORCEINLINE bool IsIn(__int32 value, __int32 min, __int32 max)
	{ return (value >= min && value <= max); }

	static FORCEINLINE bool IsIn(float value, float min, float max)
	{ return (value >= min && value <= max); }
};

