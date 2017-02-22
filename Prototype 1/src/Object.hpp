//
//  Object.hpp
//  oF_GA_FINAL
//
//  Created by Merrilee Pan on 2016-05-02.
//
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Object_hpp */

class Object {
public:
    int xPos, yPos;
    int velX, velY;
    int diam;
    
    Object();
    
    void setup(float _x, float _y);
    void update();
    void draw();
    
};