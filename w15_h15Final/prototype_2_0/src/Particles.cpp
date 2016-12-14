
#include "Particles.hpp"


Particles::Particles(){
    pos.x = ofGetWindowWidth()*0.5;
    pos.y = ofGetWindowHeight()*0.5;

    
    vel.set(0,0);
    acc.set(0,0);
    
    damping = 0.95; // de resistance!!!
    radius = 1;

    
}

void Particles::setInit(ofVec2f _pos, ofVec2f _vel) {
    pos = _pos;
    vel = _vel;
    acc.set(0,0);
    
}

//void Particles::setup(ofVec2f rVel){
//    
//    
//    
//    vel = rVel;
//    pos.x = ofGetWidth()*0.75;
//    pos.y = ofGetHeight() * 0.75;
//    //    pos.x = ofRandom(0, ofGetWidth());
//    //    pos.y = ofRandom(0, ofGetHeight());
//    
//}

void Particles::update(float _noiseNum, float _noiseX, float _noiseY, float _cosNoise, float _sinNoise){
    
    noiseNum = _noiseNum;
    noiseX = _noiseX;
    noiseY = _noiseY;
    cosNoise = _cosNoise;
    sinNoise = _sinNoise;
    
    float noise = ofNoise(pos.x * noiseX, pos.y * noiseY, ofGetElapsedTimef()* 0.2)* noiseNum;
    
    pos += ofVec2f(cos(noise * cosNoise), sin(noise * sinNoise));
    vel += acc;
    vel *= damping;
    pos += vel*2.0;
    acc *= 0.0;
    
}

void Particles::draw(){
    
    ofSetColor(255, 5);
    ofSetCircleResolution(100);
    
    radius = 0.5;
    
    ofDrawCircle(pos, radius);
    
}

void Particles::bounding(){
    
    if(pos.x < 0 + radius){
        pos.x = ofGetWidth() + radius;
    }
    
    if(pos.x > ofGetWidth()+radius){
        pos.x = 0 + radius;
    }
    
    if(pos.y < 0 +radius ){
        pos.y = ofGetHeight() + radius;
    }
    
    if(pos.y > ofGetHeight() + radius){
        pos.y = 0 + radius;
    }

}



void Particles::addRepulsion(ofVec2f _pos, float _radius, float _scale){
    
    ofVec2f diff = _pos - pos;
    if( diff.length() < _radius ){
        diff *= 2.0-diff.length()/_radius;// PRO way
        addForce(-diff*_scale);
    }
    
}

void Particles::addAttraction(ofVec2f _pos, float _radius, float _scale){
    
    ofVec2f diff = _pos - pos;
    if( diff.length() < _radius ){
        diff *= 2.0-diff.length()/_radius;
        addForce(diff*_scale);
    }
}

ofVec2f Particles::getPosition(){
    return pos;
}

float Particles::getRadius(){
    return radius;
}

void Particles::addForce(ofPoint _force){
    acc += _force;
}




