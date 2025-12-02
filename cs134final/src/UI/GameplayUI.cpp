#include "GameplayUI.h"

#include "GameManager.h"

void GameplayUI::update()
{
    UserInterface::update();
    
    scoreLabel->text = std::to_string(GameManager::getInstance().getScore()) + " pts";

    std::ostringstream timerStringStream;
    timerStringStream << std::fixed << std::setprecision(1) << GameManager::getInstance().gameTimer;
    timeLabel->text = timerStringStream.str() + " secs";
}
