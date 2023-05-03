#pragma once

#include "State.h"
#include "Snake.h"
#include "ofMain.h"
#include "ofTrueTypeFont.h"
#include <string>

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

        int score; 

        int currentFoodX;
        int currentFoodY;

        int boardSizeWidth, boardSizeHeight;
        int cellSize; // Pixels

        ofTrueTypeFont scoreText; 
        ofImage continueButton;

        bool setNotPaused() {return paused=false;}

        string powerup;
        ofTrueTypeFont powerupText;

        bool speedOn;
        bool betterApple;
        int timer;
        int fps;




        int decay = ofGetFrameRate() * 30;  
        int red = 255;
        int blue = 0;
        int green = 0;
};