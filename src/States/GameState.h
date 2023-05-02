#pragma once

#include "State.h"
#include "Snake.h"
#include "ofMain.h"
#include "ofTrueTypeFont.h"

class GameState : public State {

    private:
        bool paused=false;

    public:

        ofRectangle continueButtonRect;
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
        void mousePressed(int x, int y, int button);

        Snake* snake;
        
        bool foodSpawned = false;

        int currentFoodX;
        int currentFoodY;

        int boardSizeWidth, boardSizeHeight;
        int cellSize; // Pixels

        ofTrueTypeFont score; 
        ofImage continueButton;

        bool setNotPaused() {return paused=false;}

};