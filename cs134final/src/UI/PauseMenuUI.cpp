#include "PauseMenuUI.h"

void PauseMenuUI::onRestartButtonReleased(ofMouseEventArgs& args)
{
    // Restart the game
    std::cout << "Game restarted" << std::endl;
}

void PauseMenuUI::onQuitButtonReleased(ofMouseEventArgs& args)
{
    // Exit the app
    ofExit();
}
