#pragma once

#include "DynamicObject.h"

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

    void SetPos(double nx, double ny) override {};
    inline double GetY() override { return 0.0; };
    inline double GetX() override { return 0.0; };
    inline void SetWidth(uint16_t widthN) override {};
    inline uint16_t GetWidth() const override { return 0; };
private:

};

