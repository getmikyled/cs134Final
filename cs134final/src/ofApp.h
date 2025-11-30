#pragma once

#include "GameplayScene.h"
#include "MainMenuScene.h"
#include "ofMain.h"
#include "ofxPanel.h"
#include "Engine/Scenes/SceneManager.h"

class ofApp : public ofBaseApp{

	public:
	
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		const float WINDOW_ASPECT_RATIO = 16.0f / 9.0f;

	ofxPanel gui;
	ofxIntSlider octreeLevels;

	// Scenes
	MainMenuScene* mainMenuScene;
	GameplayScene* gameplayScene;
};
