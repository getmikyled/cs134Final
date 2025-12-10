#pragma once
#include "Label.h"
#include "UserInterface.h"
#include "YouWinUI.h"

class GameOverUI : public UserInterface
{
public:
    GameOverUI()
    {
        // Set up you win label
        gameOverLabel = new Label(0.09f);
        gameOverLabel->text = "CRASHED";
        gameOverLabel->position = ofVec2f(0.1f, 0.15f);
        uiElements.emplace_back(gameOverLabel);
        
        // Initialize play button
        mainMenuButton = new Label(0.05f);
        mainMenuButton->text = "MAIN MENU";
        mainMenuButton->position = ofVec2f(0.15f, 0.5f);
        uiElements.emplace_back(mainMenuButton);

        // Initialize quit button
        quitButton = new Label( 0.05f);
        quitButton->text = "QUIT";
        quitButton->position = ofVec2f(0.15f, 0.7f);
        uiElements.emplace_back(quitButton);
        
        ofAddListener(mainMenuButton->mousePressedEvent, this, &GameOverUI::onMainMenuButtonPressed);
        ofAddListener(quitButton->mousePressedEvent, this, &GameOverUI::onQuitButtonPressed);
    }

    void onMainMenuButtonPressed(ofMouseEventArgs& args);
    void onQuitButtonPressed(ofMouseEventArgs& args);

    Label* gameOverLabel;
    Label* mainMenuButton;    
    Label* quitButton;
};
