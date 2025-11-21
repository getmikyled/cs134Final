#pragma once

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
    void onMainMenuStateEntered();
    void onGameplayStateEntered();
    void onPausedStateEntered();
    void onGameOverStateEntered();
    void onMainMenuStateExited();
    void onGameplayStateExited();
    void onPausedStateExited();
    void onGameOverStateExited();

    int getScore();
    void addScore(int argScore);

private:
    GameState gameState = MAIN_MENU;
    int score = 0;
    
    GameManager() {} // Private constructor
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;
};
