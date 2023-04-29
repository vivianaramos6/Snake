#pragma once

class Entity{
    public:
        virtual void drawObject() = 0;
        virtual void objectSpawner() = 0;
        virtual bool checkCrashed(int x, int y) = 0;
        
};