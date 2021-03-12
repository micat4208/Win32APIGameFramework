#pragma once
#include <Windows.h>
#include <iostream>
#include <combaseapi.h>
#include <functional>

#include <vector>
#include <list>
#include <map>

#include "Log.h"
using namespace std;

#ifdef UNICODE
#define tstring wstring
#else 
#define tstring string
#endif



// Globals...
extern class CGameInstance* GameInstance;


// Operators...
template<typename ParentType, typename ChildType>
FORCEINLINE bool IsA(ChildType* childInstance)
{ return is_base_of<ParentType, ChildType>(); }

template<typename ParentType, typename ChildType>
FORCEINLINE bool IsA()
{ return is_base_of<ParentType, ChildType>(); }

template<typename TargetType, typename T>
FORCEINLINE TargetType* Cast(T* instance)
{ return dynamic_cast<TargetType*>(instance); }
