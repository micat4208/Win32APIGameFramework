#include "Object.h"

#include "../Component/Collision/Collision.h"

CObject::CObject()          { }
void CObject::Initialize()  { }
void CObject::Release()     { }
CObject::~CObject()         { }

tstring CObject::ToString() const
{

    tstring str;
    string typeString = typeid(*this).name();
    str.assign(typeString.begin(), typeString.end());

    return str;
}

