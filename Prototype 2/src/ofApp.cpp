#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    cam.initGrabber(1280, 720);
    tracker.setup();
    ofSetVerticalSync(true);
    
    score.load("CourierNew.ttf", 28);
    scoreN = 0;
    lives.load("CourierNew.ttf", 28);
    livesN = 5;
    
    for(int i=0; i<NUMCIRCLES; i++){
        circles[i].setup();
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
    
    if(tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT) > 3.0){
        ofDrawCircle(mouthSize.getCentroid2D(), 6 * tracker.getScale());
//        cout << mouthSize.getCentroid2D().x << "," << mouthSize.getCentroid2D().y << endl;
    }
    
    for(int i=0; i<NUMCIRCLES; i++){
        if((mouthSize.getCentroid2D().x < (circles[i].xPos + 25) && mouthSize.getCentroid2D().x > (circles[i].xPos - 25)) && (mouthSize.getCentroid2D().y < (circles[i].yPos + 25) && mouthSize.getCentroid2D().y > (circles[i].yPos - 25))){
            
            circles[i].xPos = ofRandom(200,600);
            circles[i].yPos = 0;
            circles[i].velY = 1;
            
            //update the score
            scoreN += 1;
        }
        
        if(circles[i].yPos > ofGetHeight() || circles[i].yPos == ofGetHeight()){
            //update lives
            livesN -= 1;
            circles[i].yPos = 0;
            circles[i].xPos = ofRandom(200,600);
            circles[i].velY = 1;
        }
        
        if(scoreN == 3 ){
            circles[i].accel = 0.2;
        }
        if (scoreN == 6){
            circles[i].accel = 0.3;
        }
        if(scoreN == 9){
            circles[i].accel = 0.4;
        }
        if(scoreN ==12){
            circles[i].accel = 0.5;
        }
        if(scoreN == 15){
            circles[i].accel = 0.6;
        }
        if(scoreN == 18){
            circles[i].accel = 0.7;
        }
        if(scoreN == 21){
            circles[i].accel = 0.8;
        }
        if(scoreN == 24){
            circles[i].accel = 0.9;
        }
        if(scoreN == 27){
            circles[i].accel = 1;
        }
        
        
    }
}

void ofApp::draw() {
    ofSetColor(255);
    
    //mirror camera view and tracker?
    cam.draw(0,0);
//            cam.draw(cam.getWidth(),0,-cam.getWidth(),cam.getHeight());
    
    ofSetLineWidth(2);
    tracker.draw();
    
    ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
    
    for(int i=0; i<NUMCIRCLES; i++){
        circles[i].draw();
    }
    
    //draw the score
    score.drawString("SCORE: " + ofToString(scoreN), ofGetWidth()-200,30);
    //chances remaining
    lives.drawString("LIVES: " + ofToString(livesN), 10,30);
    
//    if(livesN == 0){
//        //Game Over
//        ofSetColor(0);
//        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
//    }
    
}

void ofApp::keyPressed(int key) {
    if(key == 'r') {
        tracker.reset();
    }
    
}
