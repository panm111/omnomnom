#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    cam.initGrabber(1300, 700);
    tracker.setup();
    ofSetVerticalSync(true);
    ofSetFrameRate(20);
    
    score.load("Minecraft.ttf", 28);
    scoreN = 0;
    lives.load("Minecraft.ttf", 28);
    livesN = 5;
    endGame.load("Minecraft.ttf", 90);
    control.load("VCR_OSD_MONO_1.001.ttf", 20);
    
    explosion.load("Explosion.wav");
    eat.load("eat.wav");
    select.load("select.wav");
    
    gameOver.load("GameOver.png");
    controls.load("controls.png");
    start.load("start.png");
    closeControls.load("closeControls.png");
    
    cellsize = 100;
    y = 0;
    
//    numCircles = 1;
//    circles.resize(numCircles);
    
//    for(int i=0; i<circles.size(); i++){
//        circles[i].setup();
//    }

    //setting up grid
    for (int i=0; i<WIDTH; i++){
        for(int j=0; j<HEIGHT; j++){
            grid[i][j] = 0;
        }
    }
    
    //set up food items
    foods.setup();
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
//        tracker.update(toCv(cam));
        flipCam.setFromPixels(cam.getPixelsRef());
        flipCam.mirror(false, true);
        
        tracker.update(toCv(flipCam));
    }
    
    for(int i=0; i<circles.size(); i++){
        circles[i].update();
    }
    
    ofPolyline mouthSize = tracker.getImageFeature(ofxFaceTracker::INNER_MOUTH);
    ofPolyline noseBase = tracker.getImageFeature(ofxFaceTracker::NOSE_BASE);
    
    for(int i=0; i<circles.size(); i++){
//        if((mouthSize.getCentroid2D().x > (circles[i].xPos + 25) && mouthSize.getCentroid2D().x < (int(circles[i].xPos+75))) && (mouthSize.getCentroid2D().y > (int(circles[i].yPos + 25)) && mouthSize.getCentroid2D().y < (int(circles[i].yPos) +75))){
        
        if(((tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT) > 4.0) && (mouthSize.getCentroid2D().x > circles[i].xPos)) && ((tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT) > 4.0) && (mouthSize.getCentroid2D().x < circles[i].xPos+100)) && ((tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT) > 4.0) && (mouthSize.getCentroid2D().y > circles[i].yPos)) && ((tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT) > 4.0) && (mouthSize.getCentroid2D().y < circles[i].yPos +100))){
            
            circles[i].xPos = circles[i].gridPos[int(ofRandom(10))];
            circles[i].yPos = 0;
            circles[i].velY = 1;
            
            //update the score
//            if(foods.foodNumber == 0){
//                circles.clear();
//                explosion.play();
//                livesN = 0;
//            }
            
            if(foods.foodNumber == 1 || foods.foodNumber == 2 || foods.foodNumber ==3 || foods.foodNumber== 4){
                scoreN += 2;
                eat.play();
            } else{
                scoreN += 1;
                eat.play();
            }
            foods.update();
        }

        if(((noseBase.getCentroid2D().x - (25 * tracker.getScale())) < circles[i].xPos) && ((noseBase.getCentroid2D().x + (25 * tracker.getScale())) > (circles[i].xPos + 100)) && ((noseBase.getCentroid2D().y - (25 * tracker.getScale())) < circles[i].yPos) && ((noseBase.getCentroid2D().y + (25 * tracker.getScale())) > (circles[i].yPos+100))){
            if(foods.foodNumber == 0){
                circles.clear();
                explosion.play();
                livesN = 0;
            }
        }
        
        if(circles[i].yPos > ofGetHeight() || circles[i].yPos == ofGetHeight()){
            if(foods.foodNumber > 1){
                livesN -= 1;
            }
            circles[i].yPos = 0;
            circles[i].xPos = circles[i].gridPos[int(ofRandom(9))];
            circles[i].velY = 1;
            foods.update();
        }
        
        if(scoreN == 3){
            circles[i].accel = 0.4;
        }
        if(scoreN == 6){
            circles[i].accel = 0.6;
        }
        if(scoreN == 10) {
            circles[i].accel = 0.7;
        }
        if(scoreN == 15){
            circles[i].accel = 0.8;
        }
        if(scoreN == 20){
            circles[i].accel = 1.0;
        }
        if(scoreN == 25){
            circles[i].accel = 1.5;
        }
        if(scoreN == 30){
            circles[i].accel = 2.0;
        }
        if(scoreN == 35){
            circles[i].accel = 2.5;
        }
        if(scoreN == 40){
            circles[i].accel = 3.0;
        }
        if(scoreN == 45){
            circles[i].accel = 3.5;
        }
        if(scoreN == 50){
            circles[i].accel = 4.0;
        }
        if(scoreN == 55){
            circles[i].accel = 4.5;
        }
        if(scoreN == 60){
            circles[i].accel = 5.0;
        }
        if(scoreN == 65){
            circles[i].accel = 5.5;
        }
        if(scoreN == 70){
            circles[i].accel = 6.0;
        }
    }
}

void ofApp::draw() {
    
    cam.draw(cam.getWidth(),0,-cam.getWidth(),cam.getHeight());
    
//    ofSetLineWidth(2);
    tracker.draw();
    
    ofPolyline noseBase = tracker.getImageFeature(ofxFaceTracker::NOSE_BASE);
    
    for(int i=0; i<circles.size(); i++){
//            circles[i].draw();
        
        grid[int(circles[i].xPos/cellsize)][int(circles[i].yPos/cellsize)] = 1;

        for (int k=0; k<WIDTH; k++){
            for(int j=0; j<HEIGHT; j++){
                if(grid[k][j] != 0){
                    foods.draw(k*cellsize, j*cellsize);
                }
//                ofNoFill();
//                ofDrawRectangle(k*cellsize, j*cellsize, cellsize, cellsize );
            }
        }
        grid[int(circles[i].xPos/cellsize)][int(circles[i].yPos/cellsize)] = 0;
    }
    
    //draw the score
    score.drawString("SCORE: " + ofToString(scoreN), ofGetWidth()-225,50);
    //chances remaining
    lives.drawString("LIVES: " + ofToString(livesN), 10,50);
    
    if(livesN == 0){
        //Game Over
        ofSetColor(255);
        gameOver.draw(0,0);
        circles.clear();
        if(scoreN > 0 && scoreN <9){
            endGame.drawString(ofToString(scoreN), ofGetWidth()/2, (ofGetHeight()/2+120));
        }else{
            endGame.drawString(ofToString(scoreN), (ofGetWidth()/2-50), (ofGetHeight()/2+120));
        }
    }
    
    control.drawString("CONTROLS (c) RESET TRACKER (r)  ", 10, 675);
    closeControls.draw(0,0);
    controls.draw(0,0);
    start.draw(0,0);

}

void ofApp::keyPressed(int key) {
    if(key == 'r') {
        tracker.reset();
    }
    if(key == 'y'){
        numCircles = 1;
        circles.resize(numCircles);
        livesN = 5;
        scoreN = 0;
        for(int i=0; i<circles.size(); i++){
            circles[i].setup();
        }
        select.play();
    }
    if(key=='s'){
        numCircles = 1;
        circles.resize(numCircles);
        livesN = 5;
        scoreN = 0;
        for(int i=0; i<circles.size(); i++){
            circles[i].setup();
        }
        select.play();
        controls.clear();
        closeControls.clear();
        start.clear();
    }
    
    if(key == 'c'){
        controls.load("controls.png");
        closeControls.load("closeControls.png");
        closeControls.draw(0,0);
        controls.draw(0,0);
        select.play();
    }
    if(key == 'x'){
        controls.clear();
        closeControls.clear();
        select.play();
    }
}

