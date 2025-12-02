#pragma once
#include "Label.h"
#include "UserInterface.h"

class GameplayUI : public UserInterface
{
public:
    GameplayUI()
    {
        scoreLabel = new Label();
        scoreLabel->position = ofVec2f(0.05f, 0.05f);
        scoreLabel->text = "0 pts";
        scoreLabel->fontSize = 0.05f;
        uiElements.push_back(scoreLabel);
        
        timeLabel = new Label();
        timeLabel->fontColor = ofColor::grey;
        timeLabel->position = ofVec2f(0.05f, 0.2f);
        timeLabel->text = "0 Seconds";
        timeLabel->fontSize = 0.02f;
        uiElements.push_back(timeLabel);
    }

    void update() override;

    Label* scoreLabel;
    Label* timeLabel;
};
