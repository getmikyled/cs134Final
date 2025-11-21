#include "MainMenuUI.h"

void MainMenuUI::onPlayButtonPressed(ofMouseEventArgs& args)
{
    // Start game
    std::cout << "Game started" << std::endl;
}

void MainMenuUI::onQuitButtonPressed(ofMouseEventArgs& args)
{
    // Close application
    ofExit();
}
