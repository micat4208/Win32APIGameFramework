#pragma once

#include "../Math/Math.h"

enum class Axis { X, Y };

struct FVector2 final
{
public :
	float X;
	float Y;

public:
	FVector2();
	FVector2(float x, float y);

	// v1, v2 두 점 사이의 거리를 반환하는 정적 메서드
	static float Distance(const FVector2& v1, const FVector2& v2);
	static FVector2 Direction(const FVector2& from, const FVector2& to);

	// X, Y 의 값을 string 형식으로 반환합니다.
	string ToString() const;

	// 벡터의 길이를 반환합니다.
	float Length();

	// 단위 벡터를 반환합니다.
	FVector2 Normalized();




#pragma region 산술 연산자 오버로드
	FORCEINLINE FVector2 operator+(const FVector2& value)
	{
		return FVector2(X + value.X, Y + value.Y);
	}

	FORCEINLINE FVector2 operator-(const FVector2& value)
	{
		return FVector2(X - value.X, Y - value.Y);
	}

	FORCEINLINE FVector2 operator*(const FVector2& value)
	{
		return FVector2(X * value.X, Y * value.Y);
	}

	FORCEINLINE FVector2 operator/(const FVector2& value)
	{
		return FVector2(X / value.X, Y / value.Y);
	}


	FORCEINLINE FVector2 operator+(const float& value)
	{ return FVector2(X + value, Y + value); }

	FORCEINLINE FVector2 operator-(const float& value)
	{ return FVector2(X - value, Y - value); }

	FORCEINLINE FVector2 operator*(const float& value)
	{ return FVector2(X * value, Y * value); }

	FORCEINLINE FVector2 operator/(const float& value)
	{ return FVector2(X / value, Y / value); }
	
#pragma endregion

#pragma region 복합 대입 연산자 오버로드
	FORCEINLINE FVector2& operator+= (const FVector2& value)
	{
		X += value.X;
		Y += value.Y;
		return *this;
	}

	FORCEINLINE FVector2& operator-= (const FVector2& value)
	{
		X -= value.X;
		Y -= value.Y;
		return *this;
	}

	FORCEINLINE FVector2& operator*= (const FVector2& value)
	{
		X *= value.X;
		Y *= value.Y;
		return *this;
	}

	FORCEINLINE FVector2& operator/= (const FVector2& value)
	{
		X /= value.X;
		Y /= value.Y;
		return *this;
	}


	FORCEINLINE FVector2& operator+= (float value)
	{
		X += value;
		Y += value;
		return *this;
	}

	FORCEINLINE FVector2& operator-= (float value)
	{
		X -= value;
		Y -= value;
		return *this;
	}

	FORCEINLINE FVector2& operator*= (float value)
	{
		X *= value;
		Y *= value;
		return *this;
	}

	FORCEINLINE FVector2& operator/= (float value)
	{
		X /= value;
		Y /= value;
		return *this;
	}
#pragma endregion

#pragma region 복합 대입 연산자 오버로드
	// 전위 연산자
	FORCEINLINE const FVector2 operator++()
	{
		X += 1;
		Y += 1;
		return (*this);
	}

	FORCEINLINE const FVector2 operator--()
	{
		X -= 1;
		Y -= 1;
		return (*this);
	}

	// 후위 연산자
	FORCEINLINE const FVector2 operator++(int)
	{
		FVector2 prev = (*this);
		X += 1;
		Y += 1;
		return prev;
	}

	FORCEINLINE const FVector2 operator--(int)
	{
		FVector2 prev = (*this);
		X -= 1;
		Y -= 1;
		return prev;
	}
#pragma endregion

#pragma region 인덱스 연산자
	FORCEINLINE float operator[] (Axis axis)
	{
		switch (axis)
		{
		case Axis::X:	return X;
		case Axis::Y:	return Y;
		}

		return -1;
	}
#pragma endregion
};

