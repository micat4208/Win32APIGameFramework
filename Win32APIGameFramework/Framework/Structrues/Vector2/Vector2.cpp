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

string FVector2::ToString() const
{
	return "(" + to_string(X) + ", " + to_string(Y) + ")";
}

float FVector2::Length()
{
	return sqrt(pow(X, 2) + pow(Y, 2));
}

FVector2 FVector2::Normalized()
{
	float length = this->Length();
	return FVector2(X / length, Y / length);
}

