#pragma once

#include <vector>

#include "GameObject.h"

//=============================================================================================================

enum CraterSize 
{ 
	SMALL_CRATER_SIZE = 9 
};

//=============================================================================================================

class Crater : public GameObject
{
public:

	bool __fastcall isInside(double xn) const;
	
	void Draw() const override;


	void SetPos(double nx, double ny) override {};
	inline double GetY() override { return 0.0; };
	inline double GetX() override { return 0.0; };
	inline void SetWidth(uint16_t widthN) override {};
	inline uint16_t GetWidth() const override { return 0; };

private:

};

//=============================================================================================================

class Ground : public GameObject
{
public:

	Ground() { }

	void Draw() const override;

	void __fastcall AddCrater(double xn);

	void SetPos(double nx, double ny) override {};
	inline double GetY() override { return 0.0; };
	inline double GetX() override { return 0.0; };
	inline void SetWidth(uint16_t widthN) override {};
	inline uint16_t GetWidth() const override { return 0; };
private:

	bool __fastcall isInsideAnyCrater(double x) const;

	std::vector<Crater> vecCrates;
};

