//
//  Circle.hpp
//  w08_h08_openFrameworks
//
//  Created by Vivian Lee on 10/27/16.
//
//

#pragma once
#include "ofMain.h"

class Circle{
    
public:
//    Circle();
    
    void draw();
    void setup();
    void update();
    
    ofPoint pos;
    ofPoint vel;
    float radius;
    
};