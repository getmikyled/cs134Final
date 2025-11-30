#include "ofApp.h"

#include "InputSystem.h"
#include "Scenes/GameplayScene.h"
#include "Scenes/MainMenuScene.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // Set up scene manager
    mainMenuScene = new MainMenuScene();
    gameplayScene = new GameplayScene();
    
    SceneManager::getInstance().addScene(mainMenuScene);
    SceneManager::getInstance().addScene(gameplayScene);
    
    SceneManager::getInstance().setActiveScene(0);

    // Setup gui
    gui.setup();
    gui.add(octreeLevels.setup("Octree Levels", 1, 0, 20));
}

//--------------------------------------------------------------
void ofApp::update()
{
    gameplayScene->octree->octreeLevels = octreeLevels;
}

//--------------------------------------------------------------
void ofApp::draw()
{
   gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    InputSystem::getInstance().onKeyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    InputSystem::getInstance().onKeyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    InputSystem::getInstance().onMouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    InputSystem::getInstance().onMouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    InputSystem::getInstance().onMousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    InputSystem::getInstance().onMouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
    float currentRatio = static_cast<float>(w) / static_cast<float>(h);
    if (abs(currentRatio - WINDOW_ASPECT_RATIO) > 0.01f)
    {
        if (currentRatio > WINDOW_ASPECT_RATIO) {
            // Fix width
            int newWidth = int(h * WINDOW_ASPECT_RATIO);
            ofSetWindowShape(newWidth, h);
        } else {
            // Fix height
            int newHeight = int(w / WINDOW_ASPECT_RATIO);
            ofSetWindowShape(w, newHeight);
        }
    }
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
