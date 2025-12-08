#include "YouWinUI.h"

#include "GameManager.h"

void YouWinUI::onMainMenuButtonPressed(ofMouseEventArgs& args)
{
    GameManager::getInstance().setGameState(MAIN_MENU);
}

void YouWinUI::onQuitButtonPressed(ofMouseEventArgs& args)
{
    ofExit();
}