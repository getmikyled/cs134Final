#pragma once
#include <string>
#include <vector>

static class BeamableUtility
{
public:

    static std::string getRandomModel()
    {
        std::vector<std::string> beamableModels = {
            "models\\objects\\cat.obj",
            "models\\objects\\cow.obj",
            "models\\objects\\deer.obj",
            "models\\objects\\dog.obj",
            "models\\objects\\person.obj",
            "models\\objects\\pig.obj",
            "models\\objects\\car0.obj",
            "models\\objects\\car1.obj",
            "models\\objects\\car2.obj",
            "models\\objects\\car3.obj",
        };
        return beamableModels[rand() % beamableModels.size()];
    }
};
