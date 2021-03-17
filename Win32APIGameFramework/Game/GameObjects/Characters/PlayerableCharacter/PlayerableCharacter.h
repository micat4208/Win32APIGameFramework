#pragma once

#include "../Character.h"

// ADWS
#define MOVE_LEFT		0x41
#define MOVE_RIGHT		0x44
#define MOVE_UP			0x57
#define MOVE_DOWN		0x53

class CPlayerableCharacter final :
	public CCharacter
{
public :
	virtual void Initialize() override;
	virtual void Start() override;
	virtual void Tick(float dt) override;


};

