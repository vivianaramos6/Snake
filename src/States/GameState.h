#pragma once

#include "State.h"
#include "Snake.h"
#include "StaticEntity.h"
#include "ofMain.h"
#include "ofTrueTypeFont.h"
#include <string>
#include <vector>

class GameState : public State {
    public:
        GameState();
        ~GameState();
        void reset();
        void update();
        void draw();
        void keyPressed(int key);
        void foodSpawner();
        void drawFood();
        void drawStartScreen();
        void drawLostScreen();
        void drawBoardGrid();

        Snake* snake;
        
        bool foodSpawned = false;

        int currentFoodX;
        int currentFoodY;

        int boardSizeWidth, boardSizeHeight;
        int cellSize; // Pixels

        ofTrueTypeFont score; 
        bool check = true;

        int obstacleX;
        int obstacleY;
        int obstacleType; 
        vector<StaticEntity* > obstacles; 
};