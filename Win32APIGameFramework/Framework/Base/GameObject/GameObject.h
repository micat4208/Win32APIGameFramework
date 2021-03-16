#pragma once
#include "../Object/Object.h"
#include "../Component/RenderComponent/RenderComponent.h"
#include "../../Structrues/Vector2/Vector2.h"

class CGameObject : 
	public CObject
{

private :
	// 추가시킬 컴포넌트를 나타냅니다.
	list<CComponent*> CreatedComponents;

	// 추가되어 사용되는 컴포넌트를 나타냅니다.
	list<CComponent*> UsedComponents;


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

	// 컴포넌트를 추가합니다.
	template <typename ComponentClassType>
	ComponentClassType* AddComponent()
	{
		// CComponent 클래스를 상속받지 않는다면 컴포넌트를 생성하지 않습니다.
		if (!IsA<CComponent, ComponentClassType>()) return nullptr;

		// 컴포넌트 생성
		CComponent* newComponent = NewObj<ComponentClassType>();

		// 컴포넌트를 소유하는 객체를 지정합니다.
		newComponent->SetOwner(this);
		CreatedComponents.push_back(newComponent);

		// 만약 추가하는 컴포넌트가 RenderComponent 라면
		if (IsA<CRenderComponent, ComponentClassType>())
			RegisterNewRenderComponent(newComponent);

		return Cast<ComponentClassType>(newComponent);
	}

	// 추가된 컴포넌트를 얻습니다.
	template<typename ComponentClassType>
	ComponentClassType* GetComponent() const
	{
		// 찾을 컴포넌트 타입 이름을 저장합니다.
		tstring targetTypeName = typeid(ComponentClassType).name();

		for (auto iter = CreatedComponents.begin();
			iter != CreatedComponents.end(); ++iter)
		{
			// 컴포넌트의 이름을 저장합니다.
			tstring componentTypeName = typeid((*iter)).name();

			// 일치한 이름의 컴포넌트를 찾았다면 반환
			if (targetTypeName == componentTypeName)
				return Cast<ComponentClassType>(*iter);
		}

		for (auto iter = UsedComponents.begin();
			iter != UsedComponents.begin(); ++iter)
		{
			tstring componentTypeName = typeid((*iter)).name();

			// 일치한 이름의 컴포넌트를 찾았다면 반환
			if (targetTypeName == componentTypeName)
				return Cast<ComponentClassType>(*iter);
		}

		// 일치하는 컴포넌트를 찾지 못했다면
		return nullptr;
	}

private :
	void RegisterNewRenderComponent(CRenderComponent* newRenderComponent);


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

