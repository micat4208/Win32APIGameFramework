#pragma once

#include "../../../Framework/Base/GameObject/GameObject.h"

class CPlayerableCharacter final :
	public CGameObject
{
public :
	virtual void Initialize() override;
	virtual void Tick(float dt) override;


};

