#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundColor(0, 0, 0);
    ofSetFrameRate(10);

    ofSetColor(255, 255, 255);

    Ns = 4;

    cellWidth = ofGetWidth() / Ns;
    cellHeight = ofGetHeight() / Ns;

    cell.resize(cellHeight);
    for(int i=0; i<cellHeight; i++){
        cell[i].resize(cellWidth);
        for(int j=0; j<cellWidth; j++){
            cell[i][j] = ofRandom(1.0) < 0.5 ? true : false;
        }
    }
    nextCell = cell;


}

//--------------------------------------------------------------
void ofApp::update(){

    // ofSetWindowTitle(ofToString(ofGetFrameRate()));

    for(int i=0; i<cellHeight; i++){
        for(int j=0; j<cellWidth; j++){
            // cell[i][j] = ofRandom(1.0) < 0.5 ? true : false;
            int count = 0;
            for(int y=-1; y<2; y++){
                for(int x=-1; x<2; x++){
                    // if(!(y == 0 && x == 0) && 0 <= i + y && i + y < Nc && 0 <= j + x && j + x < Nc && cell[i + y][j + x])  count++;  // not torus

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
                        if(cell[idx][jdx])  count++;
                    }
                }
            }
            if(cell[i][j]){
                if(count == 2 || count == 3){
                    nextCell[i][j] = true;
                }else{
                    nextCell[i][j] = false;
                }
            }else if(count == 3){
                nextCell[i][j] = true;
            }else{
                nextCell[i][j] = false;
            }
        }
    }
    cell = nextCell;

}

//--------------------------------------------------------------
void ofApp::draw(){

    for(int i=0; i<cellHeight; i++){
        for(int j=0; j<cellWidth; j++){
            ofSetColor(0, 0, 255 * cell[i][j]);
            ofRect(Ns * j, Ns * i, Ns, Ns);
            /*
            if(cell[i][j]){
                ofRect(Ns * j, Ns * i, Ns, Ns);
            }
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
