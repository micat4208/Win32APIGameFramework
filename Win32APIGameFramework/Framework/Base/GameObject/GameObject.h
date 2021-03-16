#pragma once
#include "../Object/Object.h"
#include "../Component/RenderComponent/RenderComponent.h"
#include "../../Structrues/Vector2/Vector2.h"

class CGameObject : 
	public CObject
{

private :
	// �߰���ų ������Ʈ�� ��Ÿ���ϴ�.
	list<CComponent*> CreatedComponents;

	// �߰��Ǿ� ���Ǵ� ������Ʈ�� ��Ÿ���ϴ�.
	list<CComponent*> UsedComponents;


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

	// ������Ʈ�� �߰��մϴ�.
	template <typename ComponentClassType>
	ComponentClassType* AddComponent()
	{
		// CComponent Ŭ������ ��ӹ��� �ʴ´ٸ� ������Ʈ�� �������� �ʽ��ϴ�.
		if (!IsA<CComponent, ComponentClassType>()) return nullptr;

		// ������Ʈ ����
		CComponent* newComponent = NewObj<ComponentClassType>();

		// ������Ʈ�� �����ϴ� ��ü�� �����մϴ�.
		newComponent->SetOwner(this);
		CreatedComponents.push_back(newComponent);

		// ���� �߰��ϴ� ������Ʈ�� RenderComponent ���
		if (IsA<CRenderComponent, ComponentClassType>())
			RegisterNewRenderComponent(newComponent);

		return Cast<ComponentClassType>(newComponent);
	}

	// �߰��� ������Ʈ�� ����ϴ�.
	template<typename ComponentClassType>
	ComponentClassType* GetComponent() const
	{
		// ã�� ������Ʈ Ÿ�� �̸��� �����մϴ�.
		tstring targetTypeName = typeid(ComponentClassType).name();

		for (auto iter = CreatedComponents.begin();
			iter != CreatedComponents.end(); ++iter)
		{
			// ������Ʈ�� �̸��� �����մϴ�.
			tstring componentTypeName = typeid((*iter)).name();

			// ��ġ�� �̸��� ������Ʈ�� ã�Ҵٸ� ��ȯ
			if (targetTypeName == componentTypeName)
				return Cast<ComponentClassType>(*iter);
		}

		for (auto iter = UsedComponents.begin();
			iter != UsedComponents.begin(); ++iter)
		{
			tstring componentTypeName = typeid((*iter)).name();

			// ��ġ�� �̸��� ������Ʈ�� ã�Ҵٸ� ��ȯ
			if (targetTypeName == componentTypeName)
				return Cast<ComponentClassType>(*iter);
		}

		// ��ġ�ϴ� ������Ʈ�� ã�� ���ߴٸ�
		return nullptr;
	}

private :
	void RegisterNewRenderComponent(CRenderComponent* newRenderComponent);


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

