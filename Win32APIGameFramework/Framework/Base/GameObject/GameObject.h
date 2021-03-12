#pragma once
#include "../Object/Object.h"
#include "../../Structrues/Vector2/Vector2.h"

class CGameObject : 
	public CObject
{
protected :
	// 오브젝트의 이름
	tstring Name;

	// 이 오브젝트의 위치
	FVector2 Position;

public :
	// 이 오브젝트를 소유하는 씬 객체
	class CScene* OwnerScene;
	
public :
	CGameObject();

public :
	// 오브젝트 이름을 반환합니다.
	FORCEINLINE tstring GetObjectName() const
	{ return Name; }

	// 오브젝트 이름을 설정합니다.
	FORCEINLINE void SetObjectName(tstring newName)
	{ Name = newName; }

	// 오브젝트의 위치를 반환합니다.
	FORCEINLINE FVector2 GetPosition() const
	{ return Position; }

	// 오브젝트의 위치를 설정합니다.
	FORCEINLINE FVector2 SetPosition(FVector2 newPosition)
	{ return Position = newPosition; }
	FORCEINLINE FVector2 AddPosition(FVector2 addPosition)
	{ return Position += addPosition; }


};

