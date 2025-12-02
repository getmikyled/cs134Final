#pragma once
#include "ofTimer.h"

enum GameState
{
    MAIN_MENU = 0,
    GAMEPLAY = 1,
    PAUSED = 2,
    GAME_OVER = 3
};

class GameManager
{
public:
    static GameManager& getInstance() {
        static GameManager instance;
        return instance;
    }

    void setGameState(GameState argState);
    void onUpdateGameState();
    void onMainMenuStateEntered();
    void onMainMenuStateExited();
    void onGameplayStateEntered();
    void onGameplayStateExited();
    void onUpdateGameplayState();
    void onPausedStateEntered();
    void onGameOverStateEntered();
    void onGameOverStateExited();
    void onPausedStateExited();

    int getScore();
    void addScore(int argScore);

    void resetGameTimer();
    void startGameTimer();
    void stopGameTimer();
    float gameTimerDuration = 120;
    bool gameTimerActive = false;
    double gameTimer = 0;
    

private:
    GameState gameState = MAIN_MENU;
    int score = 0;
    
    GameManager() {} // Private constructor
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;
};
