#include "EnemyCharacter.h"

#include "../../../Components/CharacterRenderer/CharacterRenderer.h"

void CEnemyCharacter::Start()
{
	CGameObject::Start();

	AddComponent<CCharacterRenderer>();

}
