
#include "Particle.hpp"

void Particle::setup(ofVec2f rVel){
    
    vel = rVel;
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
    //        pos.x = ofRandom(0, ofGetWidth());
    //        pos.y = ofRandom(0, ofGetHeight());
    
}

void Particle::update(float _sound){
    
    sound = _sound;
    
    //    noiseNum = _noiseNum;
    //    noiseX = _noiseX;
    //    noiseY = _noiseY;
    //    cosNoise = _cosNoise;
    //    sinNoise = _sinNoise;
    
    //    float noise = ofNoise(pos.x * noiseX, pos.y * noiseY, ofGetElapsedTimef()* 0.2)* noiseNum;
    
    float noise = ofNoise(pos.x * 0.005, pos.y * 0.005, ofGetElapsedTimef()* 0.2)* 5.0;
    
    pos += ofVec2f(cos(noise * 50.5), sin(noise * 55.0));
    pos += (vel*sound)*2;
    vel *= 0.97;
    
    
    
}


void Particle::draw(float _radius){
    
    radius = _radius;
    
    ofSetColor(255, 100);
    ofSetCircleResolution(100);
        
    ofDrawCircle(pos, radius);
    
}


void Particle::bounding(){
    
    if(pos.x < 225  + radius){
        pos.x = 735 + radius;
    }
    
    if(pos.x > 735 + radius){
        pos.x = 225 + radius;
    }
    
    if(pos.y < 15 + radius){
        pos.y = 520 + radius;
    }
    
    if(pos.y > 520 + radius){
        pos.y = 15 + radius;
    }
    
    //    if(pos.x < 225|| pos.x > 735){
    //        vel.x = -vel.x;
    //    }
    //    if(pos.y < 15 || pos.y > 520){
    //        vel.y = -vel.y;
    //    }
    //
}




void Particle::addRepulsion(ofVec2f _pos, float _radius, float _scale){
    
    ofVec2f diff = _pos - pos;
    if( diff.length() < _radius ){
        diff *= 2.0+diff.length()/_radius;
        addForce(-diff*_scale);
    }
    
}

void Particle::addAttraction(ofVec2f _pos, float _radius, float _scale){
    
    ofVec2f diff = _pos - pos;
    if( diff.length() > _radius ){
        diff *= 2.0-diff.length()/_radius;
        addForce(diff*_scale);
    }
}

ofVec2f Particle::getPosition(){
    return pos;
}

float Particle::getRadius(){
    return radius;
}

void Particle::addForce(ofPoint _force){
    acc += _force;
}








