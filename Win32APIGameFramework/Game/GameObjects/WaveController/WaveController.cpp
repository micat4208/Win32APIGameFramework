#include "WaveController.h"

#include "Framework/Base/Scene/Scene.h"

#include "Game/GameObjects/Characters/EnemyCharacter/EnemyCharacter.h"


void CWaveController::Initialize()
{
	__super::Initialize();

	bAllClear = false;

	WaveInfos.push_back(1);
	//WaveInfos.push_back(10);
	//WaveInfos.push_back(15);
	//WaveInfos.push_back(20);
	WaveIterator = WaveInfos.begin();
}

void CWaveController::Start()
{
	__super::Start();
	StartWave();
}

void CWaveController::StartWave()
{
	if (bAllClear) return;

	for (int i = 0; i < (*WaveIterator); ++i)
		CreateEnemy();

	++WaveIterator;
	if (WaveIterator == WaveInfos.end())
		bAllClear = true;


}

CEnemyCharacter* CWaveController::CreateEnemy()
{
	// �� ĳ���͸� ����
	CEnemyCharacter* newEnemy = OwnerScene->NewObject<CEnemyCharacter>();
	newEnemy->WaveController = this;

	// ������ ���� ��� ����Ʈ�� ������ ���� �߰��մϴ�.
	CreatedEnemyCharacter.push_back(newEnemy);

	// �������� �߾� ��ġ�� �����մϴ�.
	FVector2 stageCenter = FVector2(WND_WIDTH * 0.5f, WND_HEIGHT * 0.5f);

	FVector2 createPosition = stageCenter + FVector2(
		FMath::FRandRange(-1.0f, 1.0f),
		FMath::FRandRange(-1.0f, 1.0f));

	// ���̰� 1�� ���Ͱ� �ǵ��� �մϴ�.
	createPosition = createPosition.Normalized();
	createPosition *= 300.0f;

	// ���� ��ġ�մϴ�.
	newEnemy->SetPosition(createPosition);

	return nullptr;
}

void CWaveController::DestroyEnemy(CEnemyCharacter* enemy)
{
	CreatedEnemyCharacter.remove(enemy);
	OwnerScene->Destroy(enemy);

	if (CreatedEnemyCharacter.size() == 0)
		StartWave();
}
