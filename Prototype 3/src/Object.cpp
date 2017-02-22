//
//  Object.cpp
//  oF_GA_FINAL_v3
//
//  Created by Merrilee Pan on 2016-05-06.
//
//

#include "Object.hpp"

Object::Object(){

}

void Object::setup(){
    
    bomb.load("Bomb.png");
    apple.load("apple.png");
    banana.load("banana.png");
    burger.load("burger.png");
    chocolate.load("chocolate.png");
    donut.load("donut.png");
    hotdog.load("hotdog.png");
    icecream.load("icecream.png");
    pizza.load("pizza.png");
    strawberry.load("strawberry.png");
    taco.load("taco.png");
    watermelon.load("watermelon.png");
    
    food[0] = bomb;
    food[1] = apple;
    food[2] = banana;
    food[3] = strawberry;
    food[4] = watermelon;
    food[5] = burger;
    food[6] = chocolate;
    food[7] = donut;
    food[8] = hotdog;
    food[9] = icecream;
    food[10] = pizza;
    food[11] = taco;
    
}

void Object::update(){
    foodNumber = ofRandom(12);
}

void Object::draw(int x, int y){

//    apple.draw(x, y);
//    banana.draw(x,y);
//    hotdog.draw(x,y);
    
    food[foodNumber].draw(x,y);

}
