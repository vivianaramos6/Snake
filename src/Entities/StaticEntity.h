#pragma once
#include "Entity.h"
#include "ofMain.h"

class StaticEntity: public Entity{
    private:
        int randomX = 50;//ofRandom(ofGetWidth()/64);
        int randomY =  50;//ofRandom(ofGetHeight()/36);
        int cellsize;
        //ofImage rock;
        bool draw;
    public:
        StaticEntity();
        StaticEntity(int x, int y, int cellsize);
        void drawObject(int x, int y);
        void objectSpawner(int x, int y);
        bool checkCrashed(int x, int y);
        bool setDraw(){
            return !draw;
        }

        void rock();
        vector<vector<int>> rockList;
};