#pragma once
#include "ofTimer.h"

enum GameState
{
    MAIN_MENU = 0,
    GAMEPLAY = 1,
    GAME_OVER = 3,
    YOU_WIN = 4
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
    void onYouWinStateEntered();
    void onYouWinStateExited();
    void onGameOverStateEntered();
    void onGameOverStateExited();

    int getScore();
    void addScore(int argScore);

    void resetGameTimer();
    void startGameTimer();
    void stopGameTimer();
    float gameTimerDuration = 60;
    bool gameTimerActive = false;
    double gameTimer = 0;
    
    GameState gameState = MAIN_MENU;

private:
    int score = 0;
    
    GameManager() {} // Private constructor
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;
};
