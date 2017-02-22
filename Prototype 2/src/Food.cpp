//
//  Food.cpp
//  oF_GA_FINAL_v2
//
//  Created by Merrilee Pan on 2016-05-04.
//
//

#include "Food.hpp"

Food::Food(){
//    velX = ofRandom(-10,10);
    velY = 1;
    accel = 0.1;
}

void Food::setup(){
    
    xPos = ofRandom(120,600);
    yPos = 0;
    diam = 50;
    
}

void Food::draw(){
    ofSetColor(255, 0, 0);
    ofDrawCircle(xPos, yPos, diam);

}

void Food::update(){
    
    yPos += velY;
    
    velY = velY + accel;
    
    cout << yPos <<  "," << velY << "," << accel << endl;
    
}


//b.remove
//b new ball
//b.destroy

//array list --> vector
//push balls into the vector