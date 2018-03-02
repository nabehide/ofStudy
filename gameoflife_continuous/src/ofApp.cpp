#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundColor(0, 0, 0);
    ofSetFrameRate(10);

    // ofSetColor(255, 255, 255);
    color = ofColor(0);

    Ns = 4;

    cellWidth = ofGetWidth() / Ns;
    cellHeight = ofGetHeight() / Ns;

    cell.resize(cellHeight);
    for(int i=0; i<cellHeight; i++){
        cell[i].resize(cellWidth);
        for(int j=0; j<cellWidth; j++){
            // cell[i][j] = ofRandom(1.0) < 0.5 ? true : false;
            cell[i][j] = ofRandom(1.0);
        }
    }
    nextCell = cell;


}

//--------------------------------------------------------------
void ofApp::update(){

    // ofSetWindowTitle(ofToString(ofGetFrameRate()));

    for(int i=0; i<cellHeight; i++){
        for(int j=0; j<cellWidth; j++){
            float count = 0;
            for(int y=-1; y<2; y++){
                for(int x=-1; x<2; x++){
                    // torus
                    if (!(y == 0 && x == 0)){
                        int idx = i + y;
                        int jdx = j + x;
                        if(idx < 0){
                            idx = cellHeight - 1;
                        }else if(cellHeight <= idx){
                            idx = 0;
                        }
                        if(jdx < 0){
                            jdx = cellWidth - 1;
                        }else if(cellWidth <= jdx){
                            jdx = 0;
                        }
                        // if(cell[idx][jdx])  count++;
                        count += cell[idx][jdx];
                    }
                }
            }
            nextCell[i][j] = count / 8.0;
            // if(nextCell[i][j] < 0.2 || 0.5 < nextCell[i][j]){

            /*
            if(2.0 / 8.0 < nextCell[i][j] && nextCell[i][j] < 3.0 / 8.0){
                nextCell[i][j] = 1.0;
            }else if(nextCell[i][j] < 1.0 / 8.0 || 4.5 / 8.0 < nextCell[i][j]){
                nextCell[i][j] = 0.0;
            }
            */

            if(0.25 < nextCell[i][j] && nextCell[i][j] < 0.35){
                nextCell[i][j] = 0.0;
            }else if(nextCell[i][j] < 0.1 || 0.95 < nextCell[i][j]){
                nextCell[i][j] = 1.0;
            }

            /*
            if(0.65 < nextCell[i][j] && nextCell[i][j] < 0.75){
                nextCell[i][j] = 1.0;
            }else if(nextCell[i][j] < 0.1 || 0.9 < nextCell[i][j]){
                nextCell[i][j] = 0.0;
            }
            */

            /*
            if(0.5 <= cell[i][j]){
                if(2.0 <= count && count <= 3.0){
                    nextCell[i][j] = true;
                }else{
                    nextCell[i][j] = false;
                }
            }else if(2.5 <= count && count <= 3.5){
                nextCell[i][j] = true;
            }else{
                nextCell[i][j] = false;
            }
            */
        }
    }
    cell = nextCell;

}

//--------------------------------------------------------------
void ofApp::draw(){

    for(int i=0; i<cellHeight; i++){
        for(int j=0; j<cellWidth; j++){
            // ofSetColor(255 * cell[i][j], 255 * cell[i][j], 255 * cell[i][j]);
            // ofSetColor(20, 50, 255 * cell[i][j]);
            color.setHsb(170, 255, 255 * cell[i][j]);
            ofSetColor(color);
            ofRect(Ns * j, Ns * i, Ns, Ns);
            /*
            ofSetColor(255, 255, 255);
            if(0.5 < cell[i][j])    ofRect(Ns * j, Ns * i, Ns, Ns);
            */
        }
    }

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
