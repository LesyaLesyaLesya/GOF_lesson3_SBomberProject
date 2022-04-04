#pragma once

#include <stdint.h>
#include "TankAdaptee.h"
#include "GameObject.h"

class DestroyableGroundObject : public GameObject
{
public:
    void Draw() const override {};

    virtual bool __fastcall isInside(double x1, double x2) const = 0;

    virtual inline uint16_t GetScore() const = 0;

protected:

};

class TankAdapter : public DestroyableGroundObject
{
private:
    TankAdaptee& tank;
public:
    TankAdapter(TankAdaptee& tank_) :tank(tank_) {};

    void Draw() const override;

    bool __fastcall isInside(double x1, double x2) const;

    void SetPos(double nx, double ny) override;
   
    
    inline uint16_t GetScore() const  override { return 0; };
    inline double GetY() override { return 0.0; };
    inline double GetX() override { return 0.0; };
    inline void SetWidth(uint16_t widthN) override {};
    inline uint16_t GetWidth() const override;
};

void TankAdapter::SetPos(double nx, double ny)
{
    tank.SetPos(nx, ny);
}
uint16_t TankAdapter::GetWidth() const
{
    return tank.GetWidth();
}
void TankAdapter::Draw() const
{
    tank.Paint();
};
bool __fastcall TankAdapter::isInside(double x1, double x2) const
{
    return tank.isInRange(x1, x2);
};

//��� ������������� � ����� ���� ����� ����� ������������, �� ������� ���.�������� ���
//���� ����� - ������ TankAdapter � ��������� ������ DestroyableGroundObject, �������
//������ ��������� ��������� tank ������ TankAdaptee.
//����� � GameObject ������� ������������ ��������� ������� :

//void SetPos(double nx, double ny) { x = nx; y = ny; }
//double GetY() const { return y; }
//double GetX() const { return x; }


//void SetWidth(uint16_t widthN) { width = widthN; }

//uint16_t GetWidth() const { return width; }

//������������� �� � ���������, ����� ��� ����������������� � ���� �� ���������
//������������� ������ TankAdaptee.��������:


/*��� ����� ��������� �������� ������ ������ TankAdaptee � ������������ ���, �� �����
��� ������������� ��������� ������ � ����.
����� ��� ������ ������ � ������� ������ TankAdapter � �� ����� ��������� �
������������ ������ SBomber.� ��� ����� ��������� ��������, ������ ��� �������� �
���� �������� �������, ��� ���� ����������� ��������� � ���������� ������������.*/
