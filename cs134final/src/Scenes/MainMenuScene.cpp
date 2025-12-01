#include "MainMenuScene.h"

#include "ofxColorPicker.h"

void MainMenuScene::onEnable()
{
    Scene::onEnable();

    ofEnableLighting();
    ofSetBackgroundColor(ofColor(34, 27, 43));
}
