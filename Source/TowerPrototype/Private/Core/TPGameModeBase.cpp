#include "Core/TPGameModeBase.h"
#include "Core/TPGameState.h"
#include "Core/TPPlayerController.h"
#include "Core/TPPlayerState.h"

ATPGameModeBase::ATPGameModeBase()
{
    GameStateClass = ATPGameState::StaticClass();
    PlayerControllerClass = ATPPlayerController::StaticClass();
    PlayerStateClass = ATPPlayerState::StaticClass();
}
