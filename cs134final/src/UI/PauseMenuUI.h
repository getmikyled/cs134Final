#pragma once
#include "Engine/UserInterface/UserInterface.h"
#include "Engine/UserInterface/Elements/Label.h"

class PauseMenuUI : public UserInterface
{
public:
    PauseMenuUI()
    {
        // Set up paused label
        pausedLabel = new Label(0.09f);
        pausedLabel->text = "PAUSED";
        pausedLabel->position = ofVec2f(0.1f, 0.15f);
        uiElements.emplace_back(pausedLabel);

        // Set up restart button
        restartButton = new Label(0.05f);
        restartButton->text = "RESTART";
        restartButton->position = ofVec2f(0.1f, 0.5f);
        ofAddListener(restartButton->mouseReleasedEvent, this, &PauseMenuUI::onRestartButtonReleased);
        uiElements.emplace_back(restartButton);

        // Set up quit button
        quitButton = new Label(0.05f);
        quitButton->text = "QUIT";
        quitButton->position = ofVec2f(0.1f, 0.7f);
        ofAddListener(quitButton->mouseReleasedEvent, this, &PauseMenuUI::onQuitButtonReleased);
        uiElements.emplace_back(quitButton);
        
    }

    Label* pausedLabel;
    Label* restartButton;
    Label* quitButton;

    void onRestartButtonReleased(ofMouseEventArgs &args);
    void onQuitButtonReleased(ofMouseEventArgs &args);
};
