#include "AIBHTrackingPlayer.h"

#include "Framework/Single/PlayerManager/PlayerManager.h"

#include "Framework/Statics/GameplayStatics.h"

#include "Game/GameObjects/Characters/PlayerableCharacter/PlayerableCharacter.h"

#include "../../AIBehaviorController.h"



void CAIBHTrackingPlayer::StartBehaivor()
{
	__super::StartBehaivor();

    DirectionUpdateMinDelay = 0.5f;
    DirectionUpdateMaxDelay = 2.0f;

    DirectionUpdateDelay = FMath::FRandRange(
        DirectionUpdateMinDelay, DirectionUpdateMaxDelay);
    LastDirectionUpdatedTime = 0.0f;

    Speed = 20.0f;

    // 플레이어블 캐릭터를 추적 타깃으로 설정합니다.
    TrackingTarget = CPlayerManager::Instance()->GetPlayerableCharacter();
}

void CAIBHTrackingPlayer::BehaviorTick(float dt)
{
    UpdateDirection();
    TrackingPlayer(dt);
}

void CAIBHTrackingPlayer::UpdateDirection()
{
    if (CGameplayStatics::GetTime() - LastDirectionUpdatedTime >= DirectionUpdateDelay)
    {
        LastDirectionUpdatedTime = CGameplayStatics::GetTime();

        // 방향 갱신 지연 시간 갱신
        DirectionUpdateDelay = FMath::FRandRange(
            DirectionUpdateMinDelay, DirectionUpdateMaxDelay);

        FVector2 enemyCharacterPosition = BehaviorController->GetOwner()->GetPosition();

        // 방향 갱신
        Direction = FVector2::Direction(
            enemyCharacterPosition, TrackingTarget->GetPosition());
    }
}

void CAIBHTrackingPlayer::TrackingPlayer(float dt)
{
    BehaviorController->GetOwner()->SetPosition(
        BehaviorController->GetOwner()->GetPosition() +
        (Direction * Speed * dt));

    // 플레이어와 적 캐릭터의 거리가 1 미만이라면 행동 종료
    if (FVector2::Distance(
        BehaviorController->GetOwner()->GetPosition(),
        TrackingTarget->GetPosition()) < 1.0f)
        bBehaviorFinished = true;

    // 추적 시작 후 3초가 경과했다면 행동 종료
    else if (CGameplayStatics::GetTime() - BehaviorStartedTime >= 3.0f)
        bBehaviorFinished = true;

}
