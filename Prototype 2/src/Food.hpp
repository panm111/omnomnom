//
//  Food.hpp
//  oF_GA_FINAL_v2
//
//  Created by Merrilee Pan on 2016-05-04.
//
//

#ifndef Food_hpp
#define Food_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Food_hpp */

class Food {
public:
    int xPos, yPos;
    float accel;
    float velX, velY;
    int diam;
    
    Food();
    
    void setup();
    void update();
    void draw();
    
//    ofImage apple;
    
};