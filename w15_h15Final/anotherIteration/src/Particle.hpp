
#pragma once
#include "ofMain.h"

class Particle {
    
public:
    
    void setup (ofVec2f rVel);
    
    void update(float _sound);
    //    void update(float _noiseNum, float _noiseX, float _noiseY, float _cosNoise, float _sinNoise);
    void draw(float _radius);

    void bounding();
    
    void addRepulsion (ofVec2f _pos, float _radius, float _scale);
    void addAttraction (ofVec2f _pos, float _radius, float _scale);
    
    
    ofVec2f getPosition();
    float   getRadius();
    void addForce(ofPoint _force);

    
    ofVec2f pos;
    ofVec2f vel;
    
    float radius;
    
    float noiseNum, noiseX, noiseY, cosNoise, sinNoise;
    float sound;

    ofVec2f force;
    ofVec2f acc;
    
    float damping;
    


};