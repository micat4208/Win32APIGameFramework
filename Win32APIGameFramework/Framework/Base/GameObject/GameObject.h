#pragma once
#include "../Object/Object.h"
#include "../../Structrues/Vector2/Vector2.h"

class CGameObject : 
	public CObject
{
protected :
	// ������Ʈ�� �̸�
	tstring Name;

	// �� ������Ʈ�� ��ġ
	FVector2 Position;

public :
	// �� ������Ʈ�� �����ϴ� �� ��ü
	class CScene* OwnerScene;
	
public :
	CGameObject();

public :
	// ������Ʈ �̸��� ��ȯ�մϴ�.
	FORCEINLINE tstring GetObjectName() const
	{ return Name; }

	// ������Ʈ �̸��� �����մϴ�.
	FORCEINLINE void SetObjectName(tstring newName)
	{ Name = newName; }

	// ������Ʈ�� ��ġ�� ��ȯ�մϴ�.
	FORCEINLINE FVector2 GetPosition() const
	{ return Position; }

	// ������Ʈ�� ��ġ�� �����մϴ�.
	FORCEINLINE FVector2 SetPosition(FVector2 newPosition)
	{ return Position = newPosition; }
	FORCEINLINE FVector2 AddPosition(FVector2 addPosition)
	{ return Position += addPosition; }


};

