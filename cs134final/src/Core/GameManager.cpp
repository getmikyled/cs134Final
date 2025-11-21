#include "GameManager.h"

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

void GameManager::onMainMenuStateEntered()
{
    SceneManager::getInstance().setActiveScene(0);
}

void GameManager::onMainMenuStateExited()
{
    
}

void GameManager::onGameplayStateEntered()
{
    SceneManager::getInstance().setActiveScene(1);
}

void GameManager::onGameplayStateExited()
{
    
}

void GameManager::onPausedStateEntered()
{
    
}

void GameManager::onPausedStateExited()
{
    
}

void GameManager::onGameOverStateEntered()
{
    
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
