#pragma once

#include "ofMain.h"
#include "ofxCv.h"

#include "ofxFaceTracker.h"
#include "CircleTracker.hpp"
#include "Object.hpp"

//#define NUMCIRCLES 1
#define WIDTH 13
#define HEIGHT 7

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    ofVideoGrabber cam;
    ofxFaceTracker tracker;
    ofImage flipCam;
    
    float grid[WIDTH][HEIGHT];
    
    int moveH;
    int moveV;
    int cellsize;
    int y;
    
    int scoreN, livesN;
    
    Object foods;
    
    vector<CircleTracker> circles;
    int numCircles;
    
    ofTrueTypeFont score, lives, endGame, control;
    
    ofSoundPlayer explosion, eat, select;
    
    ofImage gameOver, controls, start, closeControls;
    
    int toggle;
    
};
