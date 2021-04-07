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

	// ���� ����Ű ���� ����
	bool bPrevJumpKeyPressedState;

	class CPlayerAttack* PlayerAttack;

	FVector2 MousePosition;

	// �̵� ������ ��Ÿ���ϴ�.
	FVector2 MoveDirection;

	// ���������� �Էµ� ���� (�ִϸ��̼��� ����ϱ� ���� ����)
	FVector2 PrevInputDirection;

	// �̵� �ӷ��� ��Ÿ���ϴ�.
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

