#pragma once

#include "DynamicObject.h"

class Plane : public DynamicObject {
public:

    void Draw() const override;

    inline void ChangePlaneY(double dy) { yDirection += dy; }
    void SetPos(double nx, double ny) override {};
    inline double GetY() override { return 0.0; };
    inline double GetX() override { return 0.0; };
    inline void SetWidth(uint16_t widthN) override {};
    inline uint16_t GetWidth() const override { return 0; };

private:

};

