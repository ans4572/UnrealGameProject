#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TPPlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerResourceChanged);

UCLASS()
class TOWERPROTOTYPE_API ATPPlayerState : public APlayerState
{
    GENERATED_BODY()

public:
    ATPPlayerState();

    UPROPERTY(BlueprintReadOnly, Category = "Resource")
    int32 CurrentHP;

    UPROPERTY(BlueprintReadOnly, Category = "Resource")
    int32 MaxHP;

    UPROPERTY(BlueprintReadOnly, Category = "Resource")
    int32 CurrentGold;

    UPROPERTY(BlueprintReadOnly, Category = "Resource")
    int32 CurrentShard;

    UPROPERTY(BlueprintAssignable, Category = "Event")
    FOnPlayerResourceChanged OnPlayerResourceChanged;

    UFUNCTION(BlueprintCallable, Category = "Resource")
    void AddHP(int32 Delta);

    UFUNCTION(BlueprintCallable, Category = "Resource")
    void AddGold(int32 Delta);

    UFUNCTION(BlueprintCallable, Category = "Resource")
    void AddShard(int32 Delta);

private:
    int32 ClampHP(int32 Value) const;
    int32 ClampCurrency(int32 Value) const;
};
