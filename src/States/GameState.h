#pragma once

#include "State.h"
#include "Snake.h"
#include "ofMain.h"
#include "ofTrueTypeFont.h"

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

        int decay = 900;  
        int red = 255;
        int blue = 0;
        int green = 0;
        int count = 0;
};