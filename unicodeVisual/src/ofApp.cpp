#include "ofApp.h"
// #include <locale.h>
// # include <glib.h>

//--------------------------------------------------------------
void ofApp::setup(){

    // char *loc = setlocale(LC_CTYPE, "");
    // setlocale(LC_ALL, loc);
    char utf8_text = "ab";
    gunichar* codepoints = g_utf8_to_ucs4_fast(utf8_text, -1, NULL);
    cout << utf8_text << ' ' << codepoints << endl;

    ofSetFrameRate(60);
    ofSetBackgroundColor(0);

    gui.setup();

}

//--------------------------------------------------------------
void ofApp::update(){

    variable = ofRandom(0, MAX_UNICODE);

}

//--------------------------------------------------------------
void ofApp::draw(){

    // color
    int color[] = {(int)(variable / 65536) % 255, (int)(variable / 255) % 255, variable % 255};
    if(colorSelect == 0)        ofSetColor(color[0], color[1], color[2]);
    else if(colorSelect == 1)   ofSetColor(color[1], color[2], color[0]);
    else                        ofSetColor(color[2], color[0], color[1]);

    ofDrawCircle(200, 200, 100);

    string character = "A";
    ofDrawBitmapString(character, 400, 400);

    if(isShowGui)   gui.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 'h')  isShowGui = !isShowGui;
    else if(key == 'c') colorSelect = (colorSelect + 1) % 3;

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
