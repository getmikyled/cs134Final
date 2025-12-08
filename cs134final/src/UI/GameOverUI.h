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
        gameOverLabel = new Label();
        gameOverLabel->text = "GAME OVER";
        gameOverLabel->fontSize = 0.09f;
        gameOverLabel->position = ofVec2f(0.1f, 0.15f);
        uiElements.emplace_back(gameOverLabel);
        
        // Initialize play button
        mainMenuButton = new Label();
        mainMenuButton->text = "MAIN MENU";
        mainMenuButton->fontSize = 0.05f;
        mainMenuButton->position = ofVec2f(0.15f, 0.5f);
        uiElements.emplace_back(mainMenuButton);

        // Initialize quit button
        quitButton = new Label();
        quitButton->text = "QUIT";
        quitButton->fontSize = 0.05f;
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
