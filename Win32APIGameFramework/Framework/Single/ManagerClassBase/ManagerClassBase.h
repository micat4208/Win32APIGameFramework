#pragma once

#include "../../Base/Object/Object.h"
#include "../../Interfaces/ManagerClass.h"

#include "../GameInstance/GameInstance.h"

template<typename ManagerClassType>
class CManagerClassBase abstract :
	public CObject,
	public IManagerClass
{
public :
	FORCEINLINE virtual void InitializeManagerClass() override {}
	FORCEINLINE virtual void ReleaseManagerClass() override
	{ Release(); }

	FORCEINLINE static ManagerClassType* Instance()
	{
		static ManagerClassType* managerInstance = nullptr;

		return managerInstance = (managerInstance == nullptr) ?
			GameInstance->GetManagerClass<ManagerClassType>() :
			managerInstance;
	}
};
