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

    // �÷��̾�� ĳ���͸� ���� Ÿ������ �����մϴ�.
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

        // ���� ���� ���� �ð� ����
        DirectionUpdateDelay = FMath::FRandRange(
            DirectionUpdateMinDelay, DirectionUpdateMaxDelay);

        FVector2 enemyCharacterPosition = BehaviorController->GetOwner()->GetPosition();

        // ���� ����
        Direction = FVector2::Direction(
            enemyCharacterPosition, TrackingTarget->GetPosition());
    }
}

void CAIBHTrackingPlayer::TrackingPlayer(float dt)
{
    BehaviorController->GetOwner()->SetPosition(
        BehaviorController->GetOwner()->GetPosition() +
        (Direction * Speed * dt));

    // �÷��̾�� �� ĳ������ �Ÿ��� 1 �̸��̶�� �ൿ ����
    if (FVector2::Distance(
        BehaviorController->GetOwner()->GetPosition(),
        TrackingTarget->GetPosition()) < 1.0f)
        bBehaviorFinished = true;

    // ���� ���� �� 3�ʰ� ����ߴٸ� �ൿ ����
    else if (CGameplayStatics::GetTime() - BehaviorStartedTime >= 3.0f)
        bBehaviorFinished = true;

}
