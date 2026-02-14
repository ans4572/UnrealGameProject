#include "Core/TPPlayerState.h"

ATPPlayerState::ATPPlayerState()
{
    CurrentHP = 20;
    MaxHP = 30;
    CurrentGold = 10;
    CurrentShard = 0;
}

void ATPPlayerState::AddHP(int32 Delta)
{
    CurrentHP = ClampHP(CurrentHP + Delta);
    OnPlayerResourceChanged.Broadcast();
}

void ATPPlayerState::AddGold(int32 Delta)
{
    CurrentGold = ClampCurrency(CurrentGold + Delta);
    OnPlayerResourceChanged.Broadcast();
}

void ATPPlayerState::AddShard(int32 Delta)
{
    CurrentShard = ClampCurrency(CurrentShard + Delta);
    OnPlayerResourceChanged.Broadcast();
}

int32 ATPPlayerState::ClampHP(int32 Value) const
{
    return FMath::Clamp(Value, 0, MaxHP);
}

int32 ATPPlayerState::ClampCurrency(int32 Value) const
{
    return FMath::Max(0, Value);
}
