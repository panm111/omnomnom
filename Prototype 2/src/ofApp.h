#pragma once

#include "ofMain.h"
#include "ofxCv.h"

#include "ofxFaceTracker.h"
#include "Food.hpp"

#define NUMCIRCLES 1

class ofApp : public ofBaseApp{

	public:
        void setup();
        void update();
        void draw();
        void keyPressed(int key);
    
    
    ofVideoGrabber cam;
    ofxFaceTracker tracker;
    
    int moveH;
    int moveV;
    
    int scoreN, livesN;
    
    Food circles [NUMCIRCLES];
    
    ofTrueTypeFont score, lives;
};
