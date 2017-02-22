//
//  Object.hpp
//  oF_GA_FINAL_v3
//
//  Created by Merrilee Pan on 2016-05-06.
//
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Object_hpp */

class Object{
public:
    Object();
    
    void setup();
    void update();
    void draw(int x, int y);
    
    
    ofImage food[12];
    ofImage bomb, apple, banana, burger, chocolate, donut, hotdog, icecream, pizza, strawberry, taco, watermelon ;
    
    int foodNumber;
};