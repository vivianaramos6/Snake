#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetWindowTitle("Snake");

    gameState = new GameState();
    menuState = new MenuState();
    currentState = menuState;
    //loading song
    music.load("musiquita.mp3");

}

//--------------------------------------------------------------
void ofApp::update(){
    if(currentState->hasFinished()) {
        if(currentState->getNextState() == "GameState") {
            music.play();
            gameState->reset();
            currentState = gameState;
        } else if(currentState->getNextState() == "MenuState") {
            music.stop();
            menuState->reset();
            currentState = menuState;
        }
    }
    currentState->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    currentState->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    currentState->keyPressed(key);
}
//--------------------------------------------------------------