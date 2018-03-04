#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofBackground(0);
    ofHideCursor();

    fft.setup(pow(2.0, 12.0));

}

//--------------------------------------------------------------
void ofApp::update(){
    fft.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    vector<float> buffer;
    buffer = fft.getBins();

    ofNoFill();

    // size of circle
    // float offset = log10(accumulate(buffer.begin(), buffer.end(), 0) * 10000 + 1);
    float offset = 0;
    for(int i=0; i<buffer.size() - 1; i++){
        offset += abs(buffer[i + 1] - buffer[i]);
    }
    offset *= 5;

    // color
    // float color = ofMap((int)distance(buffer.begin(), *max_element(buffer.begin(), buffer.end())), 0, buffer.size(), 0, 255);
    // vector<float>::iterator iter = max_element(buffer.begin(), buffer.end());
    // int index = distance(buffer.begin(), iter);
    // float color = ofMap(index, 0, buffer.size(), 255, 0);
    // float color = ofMap(log10(index + 1), log10(1), log10(buffer.size() + 1), 255, 0);
    float color = offset * 100;
    ofSetColor(offset, offset, 255);

    ofBeginShape();
    for(int j=0; j<4; j++){
        for(int i=0; i<buffer.size(); i++){
            if(false){
                // x-y
                float x = ofMap(log10(i + 1), log10(1), log10(buffer.size() + 1), 0, ofGetWidth());
                float y = ofMap(buffer[i], 0, 1, ofGetHeight(), 0);
                ofVertex(x, y);
            }else{
                // circle
                // float r = ofMap(buffer[i], 0, 1, 0, ofGetHeight() / 2 - offset);
                float r = ofMap(buffer[i], 0, 1, 0, ofGetHeight() / 2);
                float theta = ofMap(log10(i + 1), log10(1), log10(buffer.size()), 0, M_PI / 2);
                ofVertex(ofGetWidth() / 2 + (r + offset) * sin(theta + M_PI / 2 * j), ofGetHeight() / 2 + (r + offset) * cos(theta + M_PI / 2 * j));
            }
        }
    }
    ofEndShape();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
