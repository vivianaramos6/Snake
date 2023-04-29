#include "StaticEntity.h"

StaticEntity::StaticEntity(){
    //rock.load("rock.png");
    draw = false;
}

StaticEntity::StaticEntity(int x, int y, int cellsize){
}

void StaticEntity::drawObject(int x, int y){
    
    return;
    //draw = true;

}

// void StaticEntity::rock(){
//     ofSetColor(120);
//     ofDrawRectangle(325, 150, 25, 25);
//     ofDrawRectangle(350, 150,25,25);
//     ofDrawRectangle(325, 175, 25,25);
//     ofDrawRectangle(350, 175, 25, 25); 
//     rockList = [[325,150], [350,150],[325,175], [350,175]];
// }

void StaticEntity::objectSpawner(int x, int y){
    // randomX = ofRandom(ofGetWidth()/64);
    // randomY = ofRandom(ofGetHeight()/36);
    // if (randomX != x || randomY != y){
        // ofSetColor(255);
        // ofDrawRectangle(randomX, randomY, 25, 25);
        // draw = true;
    //}   
}

bool StaticEntity::checkCrashed(int x, int y){return 0;}