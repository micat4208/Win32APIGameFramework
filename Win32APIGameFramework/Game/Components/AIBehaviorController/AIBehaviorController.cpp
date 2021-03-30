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
	// �ൿ ������ ���� ���� �ʾҴٸ� �������� �ʽ��ϴ�.
	if (!bBehaviorControlStarted) return;

	// ������ �ൿ�� ��Ÿ���ϴ�.
	CAIBehavior* behavior = Behaviors[NextBehaviorIndex];

	// ���� �ൿ �ε����� �����մϴ�.
	++NextBehaviorIndex;
	if (NextBehaviorIndex < Behaviors.size() - 1)
		NextBehaviorIndex = 0;


	// �ൿ �ʱ� ���� �ð���ŭ ����մϴ�.
	if (CGameplayStatics::GetTime() - LastBehaviorStartedTime < 
		behavior->GetBehaviorBeginDelay()) return;

	// �ൿ�� ���۽�ŵ�ϴ�.
	if (!behavior->IsStarted())
		behavior->StartBehaivor();

	// �ൿ ������ ������ �ʾҴٸ� �������� �ʽ��ϴ�.
	if (!behavior->IsAllowedBehaviorStart()) return;

	behavior->BehaviorTick(dt);

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