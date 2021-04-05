#include "Vector2.h"
#include <string>

FVector2::FVector2() : FVector2(0.f, 0.f) {}
FVector2::FVector2(float x, float y)
{
	X = x;
	Y = y;
}

float FVector2::Distance(const FVector2& v1, const FVector2& v2)
{
	return sqrt(pow(v2.X - v1.X, 2) + pow(v2.Y - v1.Y, 2));
}

FVector2 FVector2::Direction(const FVector2& from, const FVector2& to)
{
	return FVector2((to.X - from.X), (to.Y - from.Y)).Normalized();
}

tstring FVector2::ToString() const
{
	tstring str;
	string vectorToString = "(" + to_string(X) + ", " + to_string(Y) + ")";
	str.assign(vectorToString.begin(), vectorToString.end());
	return str;
}

float FVector2::Length()
{
	return sqrt(pow(X, 2) + pow(Y, 2));
}

FVector2 FVector2::Normalized()
{
	float length = this->Length();

	return FMath::Approximately(length, 0.0f) ? 
		FVector2::ZeroVector() :
		FVector2(X / length, Y / length);
}

