#include "MainMenuUI.h"

#include "Core/GameManager.h"

void MainMenuUI::onPlayButtonPressed(ofMouseEventArgs& args)
{
    // Start game
    GameManager::getInstance().setGameState(GameState::GAMEPLAY);
    std::cout << "Game started" << std::endl;
}

void MainMenuUI::onQuitButtonPressed(ofMouseEventArgs& args)
{
    // Close application
    ofExit();
}
