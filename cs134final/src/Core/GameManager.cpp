#include "GameManager.h"

#include "InputSystem.h"
#include "ofAppRunner.h"
#include "SceneManager.h"

void GameManager::setGameState(GameState argState)
{
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
        case PAUSED:
            onPausedStateExited();
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
        case PAUSED:
            onPausedStateExited();
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
    case PAUSED:
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

    // Set mouse control
    //InputSystem::getInstance().setMouseControl(false);

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


void GameManager::onPausedStateEntered()
{
    // Set mouse input
    InputSystem::getInstance().setMouseControl(true);
}

void GameManager::onPausedStateExited()
{
    
}

void GameManager::onGameOverStateEntered()
{
    // Set mouse input
    InputSystem::getInstance().setMouseControl(true);
}

void GameManager::onGameOverStateExited()
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

