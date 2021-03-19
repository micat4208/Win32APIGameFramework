#pragma once
#include "../Collision.h"

class CRectCollision :
    public CCollision
{
public :
    CRectCollision();

public :
    void SetBound(FVector2 min, FVector2 max);
    void SetBound(float width, float height);
};

