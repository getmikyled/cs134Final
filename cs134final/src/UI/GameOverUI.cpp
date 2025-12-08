#include "GameOverUI.h"
#include "GameManager.h"

void GameOverUI::onMainMenuButtonPressed(ofMouseEventArgs& args)
{
    GameManager::getInstance().setGameState(MAIN_MENU);
}

void GameOverUI::onQuitButtonPressed(ofMouseEventArgs& args)
{
    ofExit();
}