#include "Core/TPGameState.h"

ATPGameState::ATPGameState()
{
    PrimaryActorTick.bCanEverTick = true;

    CurrentPhase = ETPRoundPhase::Setup;
    SetupDuration = 60.0f;
    BattleDuration = 60.0f;
    RemainingPhaseTime = SetupDuration;
    RemainingMonsters = 10;
    CurrentRound = 1;
    BossRoundInterval = 5;
}

void ATPGameState::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    RemainingPhaseTime = FMath::Max(0.0f, RemainingPhaseTime - DeltaSeconds);
    if (RemainingPhaseTime <= KINDA_SMALL_NUMBER)
    {
        if (CurrentPhase == ETPRoundPhase::Setup)
        {
            EnterPhase(ETPRoundPhase::Battle);
        }
        else
        {
            CurrentRound++;
            EnterPhase(ETPRoundPhase::Setup);
            RemainingMonsters = 10 + (CurrentRound * 2);
        }
    }

    OnRoundDataChanged.Broadcast();
}

void ATPGameState::SetRemainingMonsters(int32 InRemainingMonsters)
{
    RemainingMonsters = FMath::Max(0, InRemainingMonsters);
    OnRoundDataChanged.Broadcast();
}

int32 ATPGameState::GetRoundsUntilBoss() const
{
    const int32 NextBossRound = ((CurrentRound / BossRoundInterval) + 1) * BossRoundInterval;
    return NextBossRound - CurrentRound;
}

FString ATPGameState::GetFormattedRemainingTime() const
{
    const int32 TotalSeconds = FMath::CeilToInt(RemainingPhaseTime);
    const int32 Minutes = TotalSeconds / 60;
    const int32 Seconds = TotalSeconds % 60;
    return FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds);
}

void ATPGameState::EnterPhase(ETPRoundPhase NewPhase)
{
    CurrentPhase = NewPhase;
    RemainingPhaseTime = (CurrentPhase == ETPRoundPhase::Setup) ? SetupDuration : BattleDuration;
    OnRoundDataChanged.Broadcast();
}
