//
//  CircleTracker.hpp
//  oF_GA_FINAL_v3
//
//  Created by Merrilee Pan on 2016-05-06.
//
//

#ifndef CircleTracker_hpp
#define CircleTracker_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* CircleTracker_hpp */

class CircleTracker {
public:
    int xPos, yPos;
    float accel;
    float velX, velY;
    int diam;
    
    CircleTracker();
    
    void setup();
    void update();
    void draw();
    
    int gridPos[9];
    
};

