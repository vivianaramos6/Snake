#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetWindowTitle("Snake");

    gameState = new GameState();
    menuState = new MenuState();
    loseState= new LoseState();
    currentState = menuState;

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
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    currentState->keyPressed(key);
}
//--------------------------------------------------------------