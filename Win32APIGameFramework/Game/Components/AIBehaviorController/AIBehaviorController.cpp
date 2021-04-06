#include "AIBehaviorController.h"

#include "../../../Framework/Statics/GameplayStatics.h"

void CAIBehaviorController::Initialize()
{
	__super::Initialize();

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

	// 행동을 시작하기 전에 등록된 모든 행동 객체들을 초기화합니다.
	for (auto behavior : Behaviors)
		behavior->InitializeBehaivor();
}

void CAIBehaviorController::BehaviorControl(float dt)
{
	// 행동 관리가 시작 되지 않았다면 실행하지 않습니다.
	if (!bBehaviorControlStarted) return;

	// 실행할 행동을 나타냅니다.
	CAIBehavior* behavior = *BehaviorIterator;

	// 다음 행동을 가리키도록 합니다.
	++BehaviorIterator;
	if (BehaviorIterator == Behaviors.end())
		BehaviorIterator = Behaviors.begin();


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