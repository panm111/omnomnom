//
//  CircleTracker.cpp
//  oF_GA_FINAL_v3
//
//  Created by Merrilee Pan on 2016-05-06.
//
//

#include "CircleTracker.hpp"

CircleTracker::CircleTracker(){
    //    velX = ofRandom(-10,10);
    velY = 1;
    accel = 0.1;
}

void CircleTracker::setup(){
    
    gridPos[0] = 200;
    gridPos[1] = 300;
    gridPos[2] = 400;
    gridPos[3] = 500;
    gridPos[4] = 600;
    gridPos[5] = 700;
    gridPos[6] = 800;
    gridPos[7] = 900;
    gridPos[8] = 1000;
    
    xPos = gridPos[int(ofRandom(9))];
//    xPos = gridPos[0];
    yPos = 0;
    diam = 100;
    
    cout << xPos << endl;
    
}

void CircleTracker::draw(){
//    ofSetColor(255, 0, 0);
    ofDrawRectangle(xPos, yPos, diam, diam);

}

void CircleTracker::update(){
    
    yPos += velY;
    
    velY = velY + accel;
    
}