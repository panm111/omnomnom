#pragma once

#include "ofMain.h"
#include "ofxCv.h"

#include "ofxFaceTracker.h"
#include "Object.hpp"

#define NUMCIRCLES 5

class ofApp : public ofBaseApp {
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
    
    Object circles [NUMCIRCLES];
    
};
