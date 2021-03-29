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
	BehaviorControl();
}

void CAIBehaviorController::StartBehaviorControl()
{
	bBehaviorControlStarted = true;
	LastBehaviorStartedTime = CGameplayStatics::GetTime();
}

void CAIBehaviorController::BehaviorControl()
{
	// �ൿ ������ ���� ���� �ʾҴٸ� �������� �ʽ��ϴ�.
	if (!bBehaviorControlStarted) return;

	// ������ �ൿ�� ��Ÿ���ϴ�.
	CAIBehavior* behavior = Behaviors[NextBehaviorIndex];

	// ���� �ൿ �ε����� �����մϴ�.
	++NextBehaviorIndex;
	if (NextBehaviorIndex < Behaviors.size() - 1)
		NextBehaviorIndex = 0;

	// �ൿ ������ ������ �ʾҴٸ� �������� �ʽ��ϴ�.
	if (!behavior->IsAllowedBehaviorStart()) return;

	// �ൿ �ʱ� ���� �ð���ŭ ����մϴ�.
	if (CGameplayStatics::GetTime() - LastBehaviorStartedTime < 
		behavior->GetBehaviorBeginDelay()) return;

	// �ൿ�� ���۽�ŵ�ϴ�.
	behavior->StartBehaivor();

	// �ൿ�� ������ �ʾҴٸ� �������� �ʽ��ϴ�.
	if (!behavior->IsBehaviorFinished()) return;

	// �ൿ ��ü �ʱ�ȭ
	behavior->InitializeBehaivor();
}

void CAIBehaviorController::Release()
{
	__super::Release();

	for (auto behavior : Behaviors)
	{ DeleteObj(behavior); }
}