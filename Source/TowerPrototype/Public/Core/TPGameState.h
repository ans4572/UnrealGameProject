#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TPGameState.generated.h"

UENUM(BlueprintType)
enum class ETPRoundPhase : uint8
{
    Setup,
    Battle
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRoundDataChanged);

UCLASS()
class TOWERPROTOTYPE_API ATPGameState : public AGameStateBase
{
    GENERATED_BODY()

public:
    ATPGameState();

    virtual void Tick(float DeltaSeconds) override;

    UPROPERTY(BlueprintReadOnly, Category = "Round")
    ETPRoundPhase CurrentPhase;

    UPROPERTY(BlueprintReadOnly, Category = "Round")
    float SetupDuration;

    UPROPERTY(BlueprintReadOnly, Category = "Round")
    float BattleDuration;

    UPROPERTY(BlueprintReadOnly, Category = "Round")
    float RemainingPhaseTime;

    UPROPERTY(BlueprintReadOnly, Category = "Round")
    int32 RemainingMonsters;

    UPROPERTY(BlueprintReadOnly, Category = "Round")
    int32 CurrentRound;

    UPROPERTY(BlueprintReadOnly, Category = "Round")
    int32 BossRoundInterval;

    UPROPERTY(BlueprintAssignable, Category = "Event")
    FOnRoundDataChanged OnRoundDataChanged;

    UFUNCTION(BlueprintCallable, Category = "Round")
    void SetRemainingMonsters(int32 InRemainingMonsters);

    UFUNCTION(BlueprintCallable, Category = "Round")
    int32 GetRoundsUntilBoss() const;

    UFUNCTION(BlueprintPure, Category = "Round")
    FString GetFormattedRemainingTime() const;

protected:
    void EnterPhase(ETPRoundPhase NewPhase);
};
