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

	// 이 오브젝트의 Tick() 메서드를 호출할 것인지를 결정합니다.
	bool bCanEverTick;

	// Start() 메서드가 호출되었는지 확인합니다.
	bool bIsStarted;

	// 해당 오브젝트가 제거 대상인지 확인합니다.
	bool bBeDestroy;
	
public :
	CGameObject();

	virtual void Initialize() override;

	// 오브젝트 초기화 이후 단 한번 호출되는 메서드
	virtual void Start();

	// 매 프레임마다 호출되는 메서드
	/// - dt : 프레임 사이 시간 간격이 전달됩니다.
	virtual void Tick(float dt);

	// 오브젝트가 제거 대상이 되었을 경우 호출되는 메서드
	/// - CObject 의 Release() 메서드보다 일찍 호출됩니다.
	virtual void OnDestory();

	virtual void Release() override;


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

