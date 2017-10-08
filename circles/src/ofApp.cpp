#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0, 0, 0);
    ofSetFrameRate(60);

    float circleRadiusMinInit = 0;
    float circleRadiusMaxInit = 20;

    circleRadiusMin.addListener(this, &ofApp::circleRadiusMinChanged);
    circleRadiusMax.addListener(this, &ofApp::circleRadiusMaxChanged);

    gui.setup();
    gui.add(circleNumber.setup("circle number", 100, 0, 1000));
    gui.add(circleRadiusMin.setup("circle radius min", circleRadiusMinInit, 0, circleRadiusMaxInit));
    gui.add(circleRadiusMax.setup("circle radius max", circleRadiusMaxInit, circleRadiusMinInit, 300));
    gui.add(circleFill.setup("circle fill", true));
    gui.add(sleepMax.setup("sleep", 10, 0, 1000));

    isGuiShow = true;

}

//--------------------------------------------------------------

void ofApp::circleRadiusMinChanged(float &circleRadiusMin){
    circleRadiusMax.setMin(circleRadiusMin);
}

//--------------------------------------------------------------

void ofApp::circleRadiusMaxChanged(float &circleRadiusMax){
    circleRadiusMin.setMax(circleRadiusMax);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    if(circleFill){
        ofFill();
    }else{
        ofNoFill();
    }
    ofSetHexColor(0x0cb0b6);
    // ofSetPolyMode(OF_POLY_WINDING_ODD);
    ofBeginShape();
    for(int i = 0; i < circleNumber; i++){
        float circleRadius = ofRandom(circleRadiusMin, circleRadiusMax);
        // ofDrawCircle(ofRandom(circleRadius, WINDOW_WIDTH * 2 - circleRadius), ofRandom(circleRadius, WINDOW_HIGHT * 2 - circleRadius), circleRadius);
        float x = ofRandom(1, WINDOW_WIDTH * 2);
        float y = ofRandom(1, WINDOW_HIGHT * 2);
        ofDrawCircle(x, y, circleRadius);
        // ofDrawCircle(ofRandom(1, WINDOW_WIDTH * 2), ofRandom(1, WINDOW_HIGHT * 2), ofRandom(circleRadiusMin, circleRadiusMax));
        // ofVertex(ofRandom(1, WINDOW_WIDTH * 2), ofRandom(1, WINDOW_HIGHT * 2));
    }
    ofEndShape();

    ofSleepMillis(ofRandom(0, sleepMax));

    if(isGuiShow){
        gui.draw();
    }

    ofGetFrameRate();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 'h'){
        isGuiShow = !isGuiShow;
    }

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
