#pragma once
#include "Engine/UserInterface/UserInterface.h"
#include "Engine/UserInterface/Elements/Label.h"

class PauseMenuUI : public UserInterface
{
public:
    PauseMenuUI()
    {
        // Set up paused label
        pausedLabel = new Label();
        pausedLabel->text = "PAUSED";
        pausedLabel->fontSize = 0.09f;
        pausedLabel->position = new ofVec2f(0.1f, 0.15f);
        uiElements.emplace_back(pausedLabel);

        // Set up restart button
        restartButton = new Label();
        restartButton->text = "RESTART";
        restartButton->fontSize = 0.05f;
        restartButton->position = new ofVec2f(0.1f, 0.5f);
        ofAddListener(restartButton->mouseReleasedEvent, this, &PauseMenuUI::onRestartButtonReleased);
        uiElements.emplace_back(restartButton);

        // Set up quit button
        quitButton = new Label();
        quitButton->text = "QUIT";
        quitButton->fontSize = 0.05f;
        quitButton->position = new ofVec2f(0.1f, 0.7f);
        ofAddListener(quitButton->mouseReleasedEvent, this, &PauseMenuUI::onQuitButtonReleased);
        uiElements.emplace_back(quitButton);
        
    }

    Label* pausedLabel;
    Label* restartButton;
    Label* quitButton;

    void onRestartButtonReleased(ofMouseEventArgs &args);
    void onQuitButtonReleased(ofMouseEventArgs &args);
};
