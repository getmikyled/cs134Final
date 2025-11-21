#pragma once
#include "Scene.h"
#include "Player/Player.h"

class GameplayScene : public Scene
{
public:
    GameplayScene()
    {
        player = createGameObject<Player>();
    }

    Player* player;
};
