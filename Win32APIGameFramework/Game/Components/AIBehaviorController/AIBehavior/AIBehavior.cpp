#include "AIBehavior.h"

#include "../../../../Framework/Statics/GameplayStatics.h"

#include "../AIBehaviorController.h"

void CAIBehavior::Initialize()
{
	bIsStarted = false;
	BehaviorBeginDelay = 0.0f;
	bAllowBehaviorStart = true;
	bBehaviorFinished = false;
}

void CAIBehavior::StartBehaivor()
{
	bIsStarted = true;
	BehaviorStartedTime = CGameplayStatics::GetTime();
}

void CAIBehavior::InitializeBehaivor()
{
	bIsStarted = false;
	bAllowBehaviorStart = true;
	bBehaviorFinished = false;
}
