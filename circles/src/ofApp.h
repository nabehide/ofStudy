#pragma once

#include "ofMain.h"
#include "ofxGui.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HIGHT = 800;

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        bool isGuiShow;

        void circleRadiusMinChanged(float & circleRadiusMin);
        void circleRadiusMaxChanged(float & circleRadiusMax);

        ofxIntSlider circleNumber;
        ofxFloatSlider circleRadiusMin;
        ofxFloatSlider circleRadiusMax;
        // ofxIntSlider circleRadiusMin;
        // ofxIntSlider circleRadiusMax;
        ofxToggle circleFill;
        ofxFloatSlider sleepMax;

        ofxPanel gui;
};
