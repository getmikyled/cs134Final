#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // Set up scene manager
    Scene* scene = new Scene();
    
    SceneManager::getInstance().scenes.push_back(scene);
    SceneManager::getInstance().activeScene = scene;
}

//--------------------------------------------------------------
void ofApp::update(){

    SceneManager::getInstance().update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    SceneManager::getInstance().draw();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
