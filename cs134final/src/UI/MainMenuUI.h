#pragma once
#include "Engine/UserInterface/UserInterface.h"
#include "Engine/UserInterface/Elements/Label.h"

class MainMenuUI : public UserInterface
{
public:
    MainMenuUI()
    {
        // Initialize play button
        playButton = new Label();
        playButton->text = "PLAY";
        playButton->fontSize = 0.05f;
        playButton->position = new ofVec2f(0.15f, 0.5f);
        uiElements.emplace_back(playButton);

        // Initialize quit button
        quitButton = new Label();
        quitButton->text = "QUIT";
        quitButton->fontSize = 0.05f;
        quitButton->position = new ofVec2f(0.15f, 0.7f);
        uiElements.emplace_back(quitButton);
        
        ofAddListener(playButton->mousePressedEvent, this, &MainMenuUI::onPlayButtonPressed);
        ofAddListener(quitButton->mousePressedEvent, this, &MainMenuUI::onQuitButtonPressed);
    }

    Label* playButton;
    Label* quitButton;

    void onPlayButtonPressed(ofMouseEventArgs& args);
    void onQuitButtonPressed(ofMouseEventArgs& args);
};
