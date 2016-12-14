#pragma once

#include "ofMain.h"
#include "Particles.hpp"
#include "ofxGui.h"

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
    
//    void addParticles();
    vector <Particles> particles;
    int num;
    
    
    ofxPanel gui;
    ofParameterGroup particleParameters;
    ofParameter<float> noiseNum;
    ofParameter<float> noiseX;
    ofParameter<float> noiseY;
    ofParameter<float> cosNoise;
    ofParameter<float> sinNoise;
    //    ofParameter<int> num;
    
    ofVec2f pos;
    
    
    ofFbo maskFbo;
    
    //    ofImage circle;
    
    //    ofFbo fbo1;
    //    ofFbo fbo2;
    
    ofSoundPlayer sound;
//    
//    float * fftSmooth;
//    int bands;
    
//    float noiseNum;
    
};
