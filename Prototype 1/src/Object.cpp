//
//  Object.cpp
//  oF_GA_FINAL
//
//  Created by Merrilee Pan on 2016-05-02.
//
//

#include "Object.hpp"

Object::Object(){
    velX = ofRandom(-10,10);
    velY = ofRandom(-10,10);
}

void Object::setup(float _x, float _y){

    xPos = _x;
    yPos = _y;
    diam = 50;
}

void Object::draw(){
    ofDrawCircle(xPos, yPos, diam);
    
}

void Object::update(){
    xPos += velX;
    yPos += velY;
    
    if(xPos>ofGetWidth()- ((diam/2) + 300)|| xPos<((diam/2) + 300)){
        velX = -velX;
    }
    
    if(yPos>ofGetHeight()- (diam/2)|| yPos<(diam/2)){
        velY = -velY;
    }
}