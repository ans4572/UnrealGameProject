#include "UI/MainHUDWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Core/TPGameState.h"
#include "Core/TPPlayerState.h"

void UMainHUDWidget::NativeConstruct()
{
    Super::NativeConstruct();
    RefreshUI();
}


void UMainHUDWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);
    RefreshUI();
}

void UMainHUDWidget::RefreshUI()
{
    const UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    const ATPGameState* GameState = World->GetGameState<ATPGameState>();
    const APlayerController* PC = World->GetFirstPlayerController();
    const ATPPlayerState* PlayerState = PC ? PC->GetPlayerState<ATPPlayerState>() : nullptr;

    if (PlayerState)
    {
        if (HPText)
        {
            HPText->SetText(FText::AsNumber(PlayerState->CurrentHP));
        }

        if (GoldText)
        {
            GoldText->SetText(FText::AsNumber(PlayerState->CurrentGold));
        }

        if (ShardText)
        {
            ShardText->SetText(FText::AsNumber(PlayerState->CurrentShard));
        }
    }

    if (!GameState)
    {
        return;
    }

    if (TimerLabelText)
    {
        const FString Prefix = (GameState->CurrentPhase == ETPRoundPhase::Setup)
            ? TEXT("[변수1] 남은 시간(정비)")
            : TEXT("[변수1] 남은 시간(전투)");
        TimerLabelText->SetText(FText::FromString(Prefix + TEXT(" ") + GameState->GetFormattedRemainingTime()));
    }

    if (TimeProgressBar)
    {
        const float TotalPhaseTime = (GameState->CurrentPhase == ETPRoundPhase::Setup)
            ? GameState->SetupDuration
            : GameState->BattleDuration;
        const float Percent = TotalPhaseTime > 0.0f ? GameState->RemainingPhaseTime / TotalPhaseTime : 0.0f;
        TimeProgressBar->SetPercent(Percent);
    }

    if (RemainingMonsterText)
    {
        RemainingMonsterText->SetText(FText::FromString(FString::Printf(TEXT("남아있는 몬스터 %d 마리"), GameState->RemainingMonsters)));
    }

    if (CurrentRoundText)
    {
        CurrentRoundText->SetText(FText::FromString(FString::Printf(TEXT("현재 %d 라운드"), GameState->CurrentRound)));
    }

    if (BossRoundText)
    {
        BossRoundText->SetText(FText::FromString(FString::Printf(TEXT("보스까지 %d 라운드"), GameState->GetRoundsUntilBoss())));
    }
}
