#pragma once

#include <stdint.h>

#include "GameObject.h"

class DynamicObject : public GameObject 
{
public:

    DynamicObject() : speed(0.0), xDirction(0.0), yDirection(0) { }

    inline void SetSpeed(double sp) { speed = sp; }
    inline void SetDirection(double dx, double dy) { xDirction = dx; yDirection = dy; }
    
    virtual void Move(uint16_t time) { x += xDirction * speed * time * 0.001; y += yDirection * speed * time * 0.001; };

    void SetPos(double nx, double ny) override {};
    inline double GetY() override = 0;
    inline double GetX() override =0;
    inline void SetWidth(uint16_t widthN) override =0;
    //inline uint16_t GetWidth() const override {};

protected:

    double speed;
    double xDirction, yDirection;

};