#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TPPlayerController.generated.h"

class UMainHUDWidget;

UCLASS()
class TOWERPROTOTYPE_API ATPPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
    TSubclassOf<UMainHUDWidget> MainHUDWidgetClass;

private:
    UPROPERTY()
    TObjectPtr<UMainHUDWidget> MainHUDWidget;
};
