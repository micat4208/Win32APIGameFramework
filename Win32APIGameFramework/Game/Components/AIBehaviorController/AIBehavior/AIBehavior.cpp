#include "AIBehavior.h"

void CAIBehavior::Initialize()
{
	BehaviorBeginDelay = BehaviorFinalDelay = 0.0f;
	bAllowBehaviorStart = true;
	bBehaviorFinished = false;
}

void CAIBehavior::InitializeBehaivor()
{
	bAllowBehaviorStart = true;
	bBehaviorFinished = false;
}
