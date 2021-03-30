#include "AIBehaviorController.h"

#include "../../../Framework/Statics/GameplayStatics.h"

void CAIBehaviorController::Initialize()
{
	__super::Initialize();

	NextBehaviorIndex = 0;
	bBehaviorControlStarted = false;
}

void CAIBehaviorController::Tick(float dt)
{
	__super::Tick(dt);
	BehaviorControl(dt);
}

void CAIBehaviorController::StartBehaviorControl()
{
	bBehaviorControlStarted = true;
	LastBehaviorStartedTime = CGameplayStatics::GetTime();
}

void CAIBehaviorController::BehaviorControl(float dt)
{
	// 행동 관리가 시작 되지 않았다면 실행하지 않습니다.
	if (!bBehaviorControlStarted) return;

	// 실행할 행동을 나타냅니다.
	CAIBehavior* behavior = Behaviors[NextBehaviorIndex];

	// 다음 행동 인덱스로 변경합니다.
	++NextBehaviorIndex;
	if (NextBehaviorIndex < Behaviors.size() - 1)
		NextBehaviorIndex = 0;


	// 행동 초기 지연 시간만큼 대기합니다.
	if (CGameplayStatics::GetTime() - LastBehaviorStartedTime < 
		behavior->GetBehaviorBeginDelay()) return;

	// 행동을 시작시킵니다.
	if (!behavior->IsStarted())
		behavior->StartBehaivor();

	// 행동 시작이 허용되지 않았다면 실행하지 않습니다.
	if (!behavior->IsAllowedBehaviorStart()) return;

	behavior->BehaviorTick(dt);

	// 행동이 끝나지 않았다면 실행하지 않습니다.
	if (!behavior->IsBehaviorFinished()) return;

	// 행동 객체 초기화
	behavior->InitializeBehaivor();
}

void CAIBehaviorController::Release()
{
	__super::Release();

	for (auto behavior : Behaviors)
	{ DeleteObj(behavior); }
}