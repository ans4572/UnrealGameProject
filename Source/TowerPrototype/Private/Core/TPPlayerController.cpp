#include "Core/TPPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "UI/MainHUDWidget.h"

void ATPPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (!MainHUDWidgetClass)
    {
        return;
    }

    MainHUDWidget = CreateWidget<UMainHUDWidget>(this, MainHUDWidgetClass);
    if (MainHUDWidget)
    {
        MainHUDWidget->AddToViewport();
    }

    bShowMouseCursor = true;
}
