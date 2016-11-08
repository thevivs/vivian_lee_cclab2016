//
//  Particles.cpp
//  week10_h10_ofParticles
//
//  Created by Vivian Lee on 11/5/16.
//
//

#include "Particles.hpp"

Particles::Particles(){
    
    setInit(ofPoint(0,0), ofPoint(0,0));
    damping = 0.9;
    
}

void Particles::setInit(ofPoint _pos, ofPoint _vel) {
    
    pos.set(_pos.x, _pos.y);
    vel.set(_vel.x, _vel.y);
    
}

void Particles::update(){
    
    vel = vel + force;
    pos = pos + vel;
    
}

void Particles::resetForce(){
    
    force.set(0, 0);
    
}

void Particles::addDamp(){
    
    force = force - vel * damping;
    
}

void Particles::addRepulsion(ofPoint _pos, float _radius, float _strength){
    
    ofPoint posForce;
    posForce.set(_pos.x, _pos.y);
    
    ofPoint diff = pos - posForce;
    
    if(diff.length() < _radius){
        diff *= ofMap(diff.length(), 0, _radius, 1.0, 0.0);
        force += diff * _strength;
    }
    
}

void Particles::addAttraction(ofPoint _pos, float _radius, float _strength){
    
    ofPoint posForce;
    posForce.set(_pos.x, _pos.y);
    
    ofPoint diff = pos - posForce;
    
    if(diff.length()< _radius){
        diff *= ofMap(diff.length(), 0, _radius, 1.0, 0.0);
        force -= diff * _strength;
        
    }
}

void Particles::draw(){
    
    ofDrawCircle(pos, 3);
    
}