#pragma once
#include "../Includes/Includes.h"

#include "../Structrues/Vector2/Vector2.h"

// ���� �÷��̿� �ʿ��� ���� �޼��带 �����ϴ� ��ƿ Ŭ����
class CGameplayStatics final
{
public :
	// ���� ���� ���� ���� �ð��� ��ȯ�մϴ�.
	static float GetTime();


	// ���콺 ��ġ�� ��ȯ�մϴ�.
	/// - translated : Ŭ���̾�Ʈ ���� ���� ��ġ�� ��ȯ�� �������� ��Ÿ���ϴ�.
	static FVector2 GetMousePosition(bool translated = true);



};

