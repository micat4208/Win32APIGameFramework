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

	// �ൿ�� �����ϱ� ���� ��ϵ� ��� �ൿ ��ü���� �ʱ�ȭ�մϴ�.
	for (auto behavior : Behaviors)
		behavior->InitializeBehaivor();
}

void CAIBehaviorController::BehaviorControl(float dt)
{
	// �ൿ ������ ���� ���� �ʾҴٸ� �������� �ʽ��ϴ�.
	if (!bBehaviorControlStarted) return;

	// ������ �ൿ�� ��Ÿ���ϴ�.
	CAIBehavior* behavior = *BehaviorIterator;

	// ���� �ൿ�� ����Ű���� �մϴ�.
	++BehaviorIterator;
	if (BehaviorIterator == Behaviors.end())
		BehaviorIterator = Behaviors.begin();


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