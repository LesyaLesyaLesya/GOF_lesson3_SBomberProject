#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

class House : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	void SetPos(double nx, double ny) override {};
	inline double GetY() override { return 0.0; };
	inline double GetX() override { return 0.0; };
	inline void SetWidth(uint16_t widthN) override {};
	inline uint16_t GetWidth() const override { return 0; };

private:

	const uint16_t score = 40;
};

