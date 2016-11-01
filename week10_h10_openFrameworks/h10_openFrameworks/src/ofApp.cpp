#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    ofBackground(255, 10);
    
    ofEnableAlphaBlending();

    for(int i = 0; i< num; i++){
        Circle tempC;
        circle.push_back(tempC);
        circle[i].setup();
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    for(int i = 0; i< num; i++){
        Circle tempC;
        circle.push_back(tempC);
        circle[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    

    for(int i = 0; i< num; i++){
        Circle tempC;
        circle.push_back(tempC);
        circle[i].draw();
    }
    
    if(ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)){
        
        ofBackground(255);
        
    }

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
