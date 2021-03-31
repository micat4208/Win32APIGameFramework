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
	// 적 캐릭터를 생성
	CEnemyCharacter* newEnemy = OwnerScene->NewObject<CEnemyCharacter>();
	newEnemy->WaveController = this;

	// 생성된 적을 담는 리스트에 생성된 적을 추가합니다.
	CreatedEnemyCharacter.push_back(newEnemy);

	// 스테이지 중앙 위치를 저장합니다.
	FVector2 stageCenter = FVector2(WND_WIDTH * 0.5f, WND_HEIGHT * 0.5f);

	FVector2 createPosition = stageCenter + FVector2(
		FMath::FRandRange(-1.0f, 1.0f),
		FMath::FRandRange(-1.0f, 1.0f));

	// 길이가 1인 벡터가 되도록 합니다.
	createPosition = createPosition.Normalized();
	createPosition *= 300.0f;

	// 적을 배치합니다.
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
