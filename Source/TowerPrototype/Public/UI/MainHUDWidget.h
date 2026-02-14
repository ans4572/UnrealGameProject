#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainHUDWidget.generated.h"

class ATPGameState;
class ATPPlayerState;
class UProgressBar;
class UTextBlock;

UCLASS()
class TOWERPROTOTYPE_API UMainHUDWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    void RefreshUI();

protected:
    virtual void NativeConstruct() override;
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> HPText;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> GoldText;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> ShardText;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> TimerLabelText;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UProgressBar> TimeProgressBar;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> RemainingMonsterText;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> CurrentRoundText;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> BossRoundText;
};
