#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
	cam.initGrabber(1280, 720);
	tracker.setup();
    ofSetVerticalSync(true);
//    moveH = ofRandom(ofGetWidth());
//    moveV = ofRandom(ofGetHeight());
    
    for(int i=0; i<NUMCIRCLES; i++){
        circles[i].setup(ofRandom(300,600), ofRandom( ofGetHeight()));
    }
}

void ofApp::update() {

	cam.update();
	if(cam.isFrameNew()) {
		tracker.update(toCv(cam));
	}
    
    for(int i=0; i<NUMCIRCLES; i++){
        circles[i].update();
    }
    
    ofPolyline mouthSize = tracker.getImageFeature(ofxFaceTracker::INNER_MOUTH);
    
    if(tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT) > 2.5){
        ofDrawCircle(mouthSize.getCentroid2D(), 6 * tracker.getScale());
        cout << mouthSize.getCentroid2D().x << "," << mouthSize.getCentroid2D().y << endl;
    }else if(tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT) > 2.5){
        
    }
    
    for(int i=0; i<NUMCIRCLES; i++){
        if((mouthSize.getCentroid2D().x < (circles[i].xPos + 25) && mouthSize.getCentroid2D().x > (circles[i].xPos - 25)) && (mouthSize.getCentroid2D().y < (circles[i].yPos + 25) && mouthSize.getCentroid2D().y > (circles[i].yPos - 25))){
            circles[i].xPos = 50000;
            circles[i].yPos = 50000;
        }
    }
    
}

void ofApp::draw() {
    ofSetColor(255);
 
    //mirror camera view and tracker?
    cam.draw(0,0);
//        cam.draw(cam.getWidth(),0,-cam.getWidth(),cam.getHeight());
    
    ofSetLineWidth(2);
    tracker.draw();
    
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
    
    for(int i=0; i<NUMCIRCLES; i++){
        circles[i].draw();
    }

    
}

void ofApp::keyPressed(int key) {
	if(key == 'r') {
		tracker.reset();
	}
    
    
}
