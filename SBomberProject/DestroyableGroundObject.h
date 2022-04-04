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

//Для использования в нашей игре класс нужно адаптировать, не изменяя его.Создадим для
//него класс - обёртку TankAdapter — наследник класса DestroyableGroundObject, который
//должен содержать экземпляр tank класса TankAdaptee.
//Также в GameObject сделаем виртуальными следующие функции :

//void SetPos(double nx, double ny) { x = nx; y = ny; }
//double GetY() const { return y; }
//double GetX() const { return x; }


//void SetWidth(uint16_t widthN) { width = widthN; }

//uint16_t GetWidth() const { return width; }

//Переопределим их в «Адаптере», чтобы они взаимодействовали с теми же функциями
//адаптируемого класса TankAdaptee.Например:


/*Нам нужно полностью обернуть объект класса TankAdaptee и адаптировать его, не ломая
уже реализованное поведение танков в игре.
Танки для нашего уровня — объекты класса TankAdapter — мы будем создавать в
конструкторе класса SBomber.И они будут корректно работать, потому что включены в
нашу иерархию классов, где есть совместимый интерфейс с поддержкой полиморфизма.*/
