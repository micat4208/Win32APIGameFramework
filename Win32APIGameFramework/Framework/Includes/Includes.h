#pragma once
#pragma warning (disable : 4838)
#pragma warning (disable : 4244)


#include <Windows.h>
#include <iostream>
#include <combaseapi.h>
#include <functional>

#include <vector>
#include <list>
#include <map>

#include <fmod.h>

#include "Log.h"
using namespace std;

#ifdef UNICODE
#define tstring wstring
#else 
#define tstring string
#endif

#ifndef WND_DEF
#define WND_DEF

#define WND_WIDTH		800
#define WND_HEIGHT		600
#endif

#ifndef COMPONENT_TAGS
#define COMPONENT_TAGS

#define TAG_PLAYER_BULLET		TEXT("PlayerBullet")
#define TAG_PLAYER_CHARACTER	TEXT("PlayerCharacter")
#define TAG_ENEMY_CHARACTER		TEXT("EnemyCharacter")

#endif



// Globals...
extern class CGameInstance* GameInstance;
extern HWND Hwnd;
extern struct FMOD_SYSTEM* SoundSystem;

// 게임 시작 시간을 저장할 변수
extern float GameStartTime;


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

FORCEINLINE tstring ToTString(string str)
{
	tstring targetTypeName;
	targetTypeName.assign(str.begin(), str.end());
	return targetTypeName;
}
