#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetWindowTitle("Snake");

    gameState = new GameState();
    menuState = new MenuState();
    loseState= new LoseState();
    currentState = menuState;

    
    //ofRectangle continueButtonRect(ofGetWidth()/2-95, ofGetHeight()/2, 200, 200);

    //loading song
    music.load("musiquita.mp3");

}

//--------------------------------------------------------------
void ofApp::update(){
    if(currentState->hasFinished()) {
        if(currentState->getNextState() == "GameState") {
            music.play();
            music.setLoop(true);
            gameState->reset();
            currentState = gameState;
        } else if(currentState->getNextState() == "MenuState") {
            music.stop();
            menuState->reset();
            currentState = menuState;
        }
        else if(currentState->getNextState() == "LoseState"){
            music.stop();
            loseState->reset();
            currentState=loseState;
        }

    }
    currentState->update();
}
//--------------------------------------------------------------
void ofApp::draw(){
    currentState->draw();
    
     //ofSetColor(ofColor::red);
     //ofDrawRectangle(ofGetWidth()/2-40, ofGetHeight()/2+70, 75, 75);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    currentState->keyPressed(key);
}
//--------------------------------------------------------------

void ofApp::mousePressed(int x,int y, int button){
    currentState->mousePressed(x,y,button);
   
    
    // if(button==OF_MOUSE_BUTTON_LEFT){
    
    //     if(continueButtonRect.inside(x, y)) {
    //         gameState->setNotPaused();
    //     }
    // }


}