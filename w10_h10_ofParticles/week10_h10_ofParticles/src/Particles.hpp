//
//  Particles.hpp
//  week10_h10_ofParticles
//
//  Created by Vivian Lee on 11/5/16.
//
//
#pragma once
#include "ofMain.h"

class Particles{
    
public:
    Particles();
    void resetForce();
    void draw();
    void addDamp();
    void setInit(ofPoint _pos, ofPoint _vel);
    void update();
    void addRepulsion (ofPoint _pos, float _radius, float _strength);
    void addAttraction (ofPoint _pos, float _radius, float _strength);
    
private:
    ofPoint pos, vel, force;
    float damping;
    
};