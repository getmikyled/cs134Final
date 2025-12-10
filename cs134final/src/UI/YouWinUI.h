#pragma once
#include "Label.h"
#include "UserInterface.h"

class YouWinUI : public UserInterface
{
public:
    YouWinUI()
    {
        // Set up you win label
        youWinLabel = new Label(0.09f);
        youWinLabel->text = "YOU WIN";
        youWinLabel->position = ofVec2f(0.1f, 0.15f);
        uiElements.emplace_back(youWinLabel);

        // Set up points label
        pointsLabel = new Label(0.03f);
        pointsLabel->text = "pts";
        pointsLabel->position = ofVec2f(0.15f, 0.35f);
        uiElements.emplace_back(pointsLabel);
        
        // Initialize play button
        mainMenuButton = new Label(0.05f);
        mainMenuButton->text = "MAIN MENU";
        mainMenuButton->position = ofVec2f(0.15f, 0.5f);
        uiElements.emplace_back(mainMenuButton);

        // Initialize quit button
        quitButton = new Label(0.05f);
        quitButton->text = "QUIT";
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
