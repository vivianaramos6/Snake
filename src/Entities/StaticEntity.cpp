#include "StaticEntity.h"

StaticEntity::StaticEntity(int x, int y, int cellsize, int type){
    this->x = x;
    this->y = y;
    this->cellsize = cellsize;
    this->type = type;
    rockImage.load("rock.png");
}

void StaticEntity::drawObject(Snake* snake){
    if ((this->getX() != snake->getHead()[0] || this->getY() != snake->getHead()[1])){
        if (this->getType() == 1)
            rock(this->getX(), this->getY());
        if (this->getType() == 2){
            flower(this->getX(),this->getY());
        }
    }
    return;
    //draw = true;

}

StaticEntity::~StaticEntity(){}

void StaticEntity::rock(int x, int y){
    ofSetColor(120 );
    ofDrawRectangle(x, y, this->getCellSize()*2,this->getCellSize()*2 );
    
}

void StaticEntity::flower(int x, int y){
    ofSetColor(255,182,193);
    ofDrawRectangle(x, y, this->getCellSize(), this->getCellSize()*3);
    ofDrawRectangle(x-25, y+25, this->getCellSize()*3, this->getCellSize());
    ofSetColor(253,253,150);
    ofDrawRectangle(x, y+25, this->getCellSize(), this->getCellSize());
}

void StaticEntity::objectSpawner(int x, int y){
    // randomX = ofRandom(ofGetWidth()/64);
    // randomY = ofRandom(ofGetHeight()/36);
    // if (randomX != x || randomY != y){
        // ofSetColor(255);
        // ofDrawRectangle(randomX, randomY, 25, 25);
        // draw = true;
    //}   
}

void StaticEntity::checkCrashed(Snake* snake){
    if (snake->getHead()[0]==this->getX() && snake->getHead()[1] == this->getY()){
        snake->setCrashed();
    }
}