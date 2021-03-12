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
	virtual void InitializeManagerClass() override {}
	virtual void ReleaseManagerClass() override;

	FORCEINLINE static ManagerClassType* Instance()
	{
		static ManagerClassType* managerInstance = nullptr;

		return managerInstance = (managerInstance == nullptr) ?
			GameInstance->GetManagerClass<ManagerClassType>() :
			managerInstance;
	}
};

template<typename ManagerClassType>
inline void CManagerClassBase<ManagerClassType>::ReleaseManagerClass()
{
	Release();
}
