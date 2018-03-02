#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	// ofSetupOpenGL(WINDOW_HIGHT, WINDOW_WIDTH, OF_WINDOW);			// <-------- setup the GL context
	// ofSetupOpenGL(1024, 768, OF_FULLSCREEN);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:

    ofGLWindowSettings settings;
    settings.setGLVersion(3, 2); 
    settings.width = 1024;
    settings.height = 768;
    ofCreateWindow(settings);

	ofRunApp( new ofApp());

}
