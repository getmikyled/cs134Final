#pragma once
#include "Label.h"
#include "UserInterface.h"

class YouWinUI : public UserInterface
{
public:
    YouWinUI()
    {
        // Set up you win label
        youWinLabel = new Label();
        youWinLabel->text = "YOU WIN";
        youWinLabel->fontSize = 0.09f;
        youWinLabel->position = ofVec2f(0.1f, 0.15f);
        uiElements.emplace_back(youWinLabel);
        
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
        
        ofAddListener(mainMenuButton->mousePressedEvent, this, &YouWinUI::onMainMenuButtonPressed);
        ofAddListener(quitButton->mousePressedEvent, this, &YouWinUI::onQuitButtonPressed);
    }

    void onMainMenuButtonPressed(ofEventArgs& args);
    void onQuitButtonPressed(ofEventArgs& args);

    Label* youWinLabel;
    Label* mainMenuButton;    
    Label* quitButton;
};
