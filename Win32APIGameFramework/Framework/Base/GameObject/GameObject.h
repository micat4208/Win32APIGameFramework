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

	// �� ������Ʈ�� Tick() �޼��带 ȣ���� �������� �����մϴ�.
	bool bCanEverTick;

	// Start() �޼��尡 ȣ��Ǿ����� Ȯ���մϴ�.
	bool bIsStarted;

	// �ش� ������Ʈ�� ���� ������� Ȯ���մϴ�.
	bool bBeDestroy;
	
public :
	CGameObject();

	virtual void Initialize() override;

	// ������Ʈ �ʱ�ȭ ���� �� �ѹ� ȣ��Ǵ� �޼���
	virtual void Start();

	// �� �����Ӹ��� ȣ��Ǵ� �޼���
	/// - dt : ������ ���� �ð� ������ ���޵˴ϴ�.
	virtual void Tick(float dt);

	// ������Ʈ�� ���� ����� �Ǿ��� ��� ȣ��Ǵ� �޼���
	/// - CObject �� Release() �޼��庸�� ���� ȣ��˴ϴ�.
	virtual void OnDestory();

	virtual void Release() override;


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

