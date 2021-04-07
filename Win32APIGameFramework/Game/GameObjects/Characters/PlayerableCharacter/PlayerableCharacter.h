#pragma once

#include "../Character.h"

// ADWS
#ifndef MOVE_KEY_DEFINE
#define MOVE_KEY_DEFINE

#define MOVE_LEFT		0x41
#define MOVE_RIGHT		0x44
#define MOVE_UP			0x57
#define MOVE_DOWN		0x53
#endif

class CPlayerableCharacter final :
	public CCharacter
{
private :
	class CPlayerMovement* PlayerMovement;

	// 이전 점프키 눌림 상태
	bool bPrevJumpKeyPressedState;

	class CPlayerAttack* PlayerAttack;

	FVector2 MousePosition;

	// 이동 방향을 나타냅니다.
	FVector2 MoveDirection;

	// 마지막으로 입력된 방향 (애니메이션을 재생하기 위해 선언)
	FVector2 PrevInputDirection;

	// 이동 속력을 나타냅니다.
	float MaxMoveSpeed;
	
	

public :
	virtual void Initialize() override;
	virtual void Start() override;
	virtual void Tick(float dt) override;

protected :
	virtual void OnCharacterDie() override;

private :
	void InputKey(float dt);

public :
	FORCEINLINE class CPlayerAttack* GetPlayerAttack() const
	{ return PlayerAttack; }


};

