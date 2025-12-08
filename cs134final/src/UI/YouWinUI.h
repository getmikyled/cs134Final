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

        // Set up points label
        pointsLabel = new Label();
        pointsLabel->text = "pts";
        pointsLabel->fontSize = 0.03f;
        pointsLabel->position = ofVec2f(0.15f, 0.35f);
        uiElements.emplace_back(pointsLabel);
        
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

    void onMainMenuButtonPressed(ofMouseEventArgs& args);
    void onQuitButtonPressed(ofMouseEventArgs& args);

    Label* youWinLabel;
    Label* pointsLabel;
    Label* mainMenuButton;    
    Label* quitButton;
};
