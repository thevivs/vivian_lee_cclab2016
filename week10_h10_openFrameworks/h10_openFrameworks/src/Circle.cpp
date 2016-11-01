//
//  Circle.cpp
//  w08_h08_openFrameworks
//
//  Created by Vivian Lee on 10/27/16.
//
//

#include "Circle.hpp"


void Circle::setup(){
    
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
    
    vel.x = ofRandom(0, 5);
    vel.y = ofRandom(0, 5);
    
    
}


void Circle::draw(){
    
    radius = 10;
    
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    ofDrawCircle(pos, radius);
    
}


void Circle::update(){
    
    pos.x += vel.x *5;
    pos.y += vel.y *5;
    
    if(pos.x < 0 + radius || pos.x > ofGetWidth()){
        vel.x = vel.x * -1;
        
    }
    
    
    if(pos.y < 0 || pos.y > ofGetHeight()){
        vel.y = vel.y * -1;
    }
    
    
    
    
}