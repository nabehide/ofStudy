#pragma once

#include "ofMain.h"
#include "ofxGui.h"

const int WIDNOW_WIDTH = 1024;
const int WIDNOW_HIGHT = 800;

const int MAX_UNICODE = 1048575;  // 16**5

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

        int variable;
        short int colorSelect = 0;
        bool isShowGui = true;

        // GUI
        ofxPanel gui;
};
