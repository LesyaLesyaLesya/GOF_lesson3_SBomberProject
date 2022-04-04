#pragma once

class GameObject {
public:

    GameObject() : x(0.0), y(0.0), width(0) { }
    virtual ~GameObject();

    virtual void Draw() const = 0;

    //inline void SetPos(double nx, double ny) { x = nx; y = ny; }
    virtual void SetPos(double nx, double ny) = 0;

    //inline double GetY() const { return y; }
    //inline double GetX() const { return x; }

    virtual inline double GetY() = 0;
    virtual inline double GetX() = 0;

    //inline void SetWidth(uint16_t widthN) { width = widthN; }
    //inline uint16_t GetWidth() const { return width; }

    virtual inline void SetWidth(uint16_t widthN) = 0;
    virtual inline uint16_t GetWidth() const = 0;

protected:

    double x, y;
    uint16_t width;
};