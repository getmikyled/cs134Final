#include "GameManager.h"

#include "GameplayScene.h"
#include "InputSystem.h"
#include "ofAppRunner.h"
#include "SceneManager.h"

void GameManager::setGameState(GameState argState)
{
    if (gameState == argState)
    {
        return;
    }
    
    GameState prevState = gameState;
    gameState = argState;

    // On exit state methods
    switch (prevState)
    {
        case MAIN_MENU:
            onMainMenuStateExited();
            break;
        case GAME_OVER:
            onGameOverStateExited();
            break;
        case GAMEPLAY:
            onGameplayStateExited();
            break;
        case YOU_WIN:
            onYouWinStateExited();
            break;
    }

    // On enter state methods
    switch (gameState)
    {
        case MAIN_MENU:
            onMainMenuStateEntered();
            break;
        case GAME_OVER:
            onGameOverStateEntered();
            break;
        case GAMEPLAY:
            onGameplayStateEntered();
            break;
        case YOU_WIN:
            onYouWinStateEntered();
            break;
    }
}

void GameManager::onUpdateGameState()
{
    switch (gameState)
    {
    case MAIN_MENU:
    case GAME_OVER:
        break;
    case GAMEPLAY:
        onUpdateGameplayState();
        break;
    }
}


void GameManager::onMainMenuStateEntered()
{
    // Set mouse input
    InputSystem::getInstance().setMouseControl(true);
    
    // Set active scene
    SceneManager::getInstance().setActiveScene(0);
}

void GameManager::onMainMenuStateExited()
{
    
}

void GameManager::onGameplayStateEntered()
{
    // Reset game timer
    resetGameTimer();
    startGameTimer();

    // Set ui
    GameplayScene* gameplayScene = dynamic_cast<GameplayScene*>(SceneManager::getInstance().getActiveScene());
    if (gameplayScene)
    {
        gameplayScene->setUserInterface(gameplayScene->gameplayUi);
    }

    // Set mouse control
    InputSystem::getInstance().setMouseControl(false);

    // Set active scene
    SceneManager::getInstance().setActiveScene(1);
}

void GameManager::onGameplayStateExited()
{
    
}

void GameManager::onUpdateGameplayState()
{
    if (gameTimerActive)
    {
        gameTimer -= ofGetLastFrameTime();

        if (gameTimer <= 0)
        {
            setGameState(GAME_OVER);
        }
    }
}

void GameManager::onGameOverStateEntered()
{
    // Set mouse input
    InputSystem::getInstance().setMouseControl(true);

    GameplayScene* gameplayScene = dynamic_cast<GameplayScene*>(SceneManager::getInstance().getActiveScene());
    if (gameplayScene)
    {
        gameplayScene->setUserInterface(gameplayScene->gameOverUi);
    }
}

void GameManager::onGameOverStateExited()
{
    
}

void GameManager::onYouWinStateEntered()
{
    // Set mouse input
    InputSystem::getInstance().setMouseControl(true);

    GameplayScene* gameplayScene = dynamic_cast<GameplayScene*>(SceneManager::getInstance().getActiveScene());
    if (gameplayScene)
    {
        gameplayScene->setUserInterface(gameplayScene->youWinUi);
    }
}

void GameManager::onYouWinStateExited()
{
    
}



int GameManager::getScore()
{
    return score;
}


void GameManager::addScore(int argScore)
{
    score += argScore;
}

void GameManager::resetGameTimer()
{
    gameTimer = gameTimerDuration;
}


void GameManager::startGameTimer()
{
    gameTimerActive = true;
}

void GameManager::stopGameTimer()
{
    gameTimerActive = false;
}

