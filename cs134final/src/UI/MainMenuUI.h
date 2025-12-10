#pragma once
#include "Engine/UserInterface/UserInterface.h"
#include "Engine/UserInterface/Elements/Label.h"

class MainMenuUI : public UserInterface
{
public:
    MainMenuUI()
    {
        // Set up paused label
        titleLabel = new Label(0.09f);
        titleLabel->text = "UFO";
        titleLabel->position = ofVec2f(0.1f, 0.15f);
        uiElements.emplace_back(titleLabel);
        
        // Initialize play button
        playButton = new Label(0.05f);
        playButton->text = "PLAY";
        playButton->position = ofVec2f(0.15f, 0.5f);
        uiElements.emplace_back(playButton);

        // Initialize quit button
        quitButton = new Label(0.05f);
        quitButton->text = "QUIT";
        quitButton->position = ofVec2f(0.15f, 0.7f);
        uiElements.emplace_back(quitButton);
        
        ofAddListener(playButton->mousePressedEvent, this, &MainMenuUI::onPlayButtonPressed);
        ofAddListener(quitButton->mousePressedEvent, this, &MainMenuUI::onQuitButtonPressed);
    }

    Label* titleLabel;
    Label* playButton;
    Label* quitButton;

    void onPlayButtonPressed(ofMouseEventArgs& args);
    void onQuitButtonPressed(ofMouseEventArgs& args);
};
