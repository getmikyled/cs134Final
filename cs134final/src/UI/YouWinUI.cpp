#include "YouWinUI.h"

#include "GameManager.h"

void YouWinUI::onMainMenuButtonPressed(ofEventArgs& args)
{
    GameManager::getInstance().setGameState(MAIN_MENU);
}

void onQuitButtonPressed(ofEventArgs& args)
{
    ofExit();
}