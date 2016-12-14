
#pragma once
#include "ofMain.h"

class Particles {
    
public:
    
    Particles();
    
    void setInit(ofVec2f _pos, ofVec2f _vel);
//    void setup (ofVec2f rVel);
    void update(float _noiseNum, float _noiseX, float _noiseY, float _cosNoise, float _sinNoise);
    void draw();
    void bounding();
    void addRepulsion (ofVec2f _pos, float _radius, float _scale);
    void addAttraction (ofVec2f _pos, float _radius, float _scale);
//    void resetForce();
//    void addDamp();
    
    
    ofVec2f getPosition();
    float   getRadius();
    void addForce(ofPoint _force);
    

    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f force;
    ofVec2f acc;
    
    float damping;
    
    float radius;
    
    float noiseNum, noiseX, noiseY, cosNoise, sinNoise;
    
    
};