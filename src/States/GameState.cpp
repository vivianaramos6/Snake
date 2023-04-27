#include "GameState.h"

//--------------------------------------------------------------
GameState::GameState() {
    foodSpawned = false;
    cellSize = 25;
    boardSizeWidth = 64;
    boardSizeHeight = 36;
    snake = new Snake(cellSize, boardSizeWidth, boardSizeHeight);
    score.load("gameFont.ttf", 15);
    continueButton.load("continue_button.png");
}
//--------------------------------------------------------------
GameState::~GameState() {
    delete snake;
}
//--------------------------------------------------------------
void GameState::reset() {
    delete snake;
    snake = new Snake(cellSize, boardSizeWidth, boardSizeHeight);
    foodSpawned = false;
    setFinished(false);
    setNextState("");
}
//--------------------------------------------------------------
void GameState::update() {
    if(paused){
        return;
    }
    else{

    if(snake->isCrashed()) {
        this->setNextState("LoseState");
        this->setFinished(true);
        return;
    }

    if(snake->getHead()[0] == currentFoodX && snake->getHead()[1] == currentFoodY) {
        snake->grow();
        foodSpawned = false;
    }

    foodSpawner();
    if(ofGetFrameNum() % 10 == 0) {
        snake->update();
    }
    }

}
//--------------------------------------------------------------
void GameState::draw() {
    drawBoardGrid();
    snake->draw();
    drawFood();
    score.drawString("Score:" + to_string(snake->getCounter()), ofGetWidth()/2 - 45, 25);
    if(paused) {
        isPaused();//added the score display in the game using a getter. 
}
}
//--------------------------------------------------------------
void GameState::keyPressed(int key) {

    if(key != OF_KEY_LEFT && key != OF_KEY_RIGHT && key != OF_KEY_UP && key != OF_KEY_DOWN && key !='u' && key != 'a' && !-'p') { return; }

    switch(key) {
        case OF_KEY_LEFT:
            snake->changeDirection(LEFT);
            break;
        case OF_KEY_RIGHT:
            snake->changeDirection(RIGHT);
            break;
        case OF_KEY_UP:
            snake->changeDirection(UP);
            break;
        case OF_KEY_DOWN:
            snake->changeDirection(DOWN);
            break;
        //undo case
        case 'u':
            if(snake->getBody().size()>2){
                snake->shrink();
            }
            break;
        case 'a':
            snake->addTen();
            break;
        case 'p':
        paused=!paused;
        
        break;
    }
}
//--------------------------------------------------------------
void GameState::foodSpawner() {
    if(!foodSpawned) {
        bool isInSnakeBody;
        do {
            isInSnakeBody = false;
            currentFoodX = ofRandom(1, boardSizeWidth-1);
            currentFoodY = ofRandom(1, boardSizeHeight-1);
            for(unsigned int i = 0; i < snake->getBody().size(); i++) {
                if(currentFoodX == snake->getBody()[i][0] and currentFoodY == snake->getBody()[i][1]) {
                    isInSnakeBody = true;
                }
            }
        } while(isInSnakeBody);
        foodSpawned = true;
    }
}
//--------------------------------------------------------------
void GameState::drawFood() {
    ofSetColor(ofColor::red);
    if(foodSpawned) {
        ofDrawRectangle(currentFoodX*cellSize, currentFoodY*cellSize, cellSize, cellSize);
    }
}
//--------------------------------------------------------------
void GameState::drawStartScreen() {
    ofSetColor(ofColor::black);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofSetColor(ofColor::white);
    string text = "Press any arrow key to start.";
    ofDrawBitmapString(text, ofGetWidth()/2-8*text.length()/2, ofGetHeight()/2-11);
    return;
}
//--------------------------------------------------------------
void GameState::isPaused(){
    if(paused){
        
         ofSetColor(0,0,0,200);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());

    ofSetColor(255);
        continueButton.draw(ofGetWidth()/2-95,ofGetHeight()/2,200,200);
    

    }
    else{
        return;
    }


}
//--------------------------------------------------------------
void GameState::mousePressed(int x, int y, int button){

ofRectangle continueButtonRect(ofGetWidth()/2-40, ofGetHeight()/2+70, 75, 75);
    if(button==OF_MOUSE_BUTTON_LEFT){
    
        if(continueButtonRect.inside(x, y)) {
          paused=false;
        }
    }
}






// void GameState::drawLostScreen() {
//     ofSetColor(ofColor::black);
//     ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
//     ofSetColor(ofColor::white);
//     string text = "You lost! Press any arrow key to play again";
//     string text2 = "or press ESC to exit.";
//     ofDrawBitmapString(text, ofGetWidth()/2-8*text.length()/2, ofGetHeight()/2-11);
//     ofDrawBitmapString(text2, ofGetWidth()/2-8*text2.length()/2, ofGetHeight()/2+2);
//     return;
// }
//--------------------------------------------------------------
void GameState::drawBoardGrid() {
    
    ofDrawGrid(25, 64, false, false, false, true);
    
    // ofSetColor(ofColor::white);
    // for(int i = 0; i <= boardSize; i++) {
    //     ofDrawLine(i*cellSize, 0, i*cellSize, ofGetHeight());
    //     ofDrawLine(0, i*cellSize, ofGetWidth(), i*cellSize);
    // }
}
//--------------------------------------------------------------

