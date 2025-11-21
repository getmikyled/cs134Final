#include "ofApp.h"

#include "Scenes/MainMenu/MainMenuScene.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // Set up scene manager

    MainMenuScene* mainMenuScene = new MainMenuScene();
    
    SceneManager::getInstance().addScene(mainMenuScene);
    SceneManager::getInstance().setActiveScene(mainMenuScene);
}

//--------------------------------------------------------------
void ofApp::update()
{
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
