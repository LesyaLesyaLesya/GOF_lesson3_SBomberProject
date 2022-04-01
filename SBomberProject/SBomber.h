#pragma once

#include <vector>
#include <memory>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "MyTools.h"

class SBomber
{
public:

    SBomber(std::shared_ptr<MyTools::ILogger> logger);
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

    class BombIterator { // «Итератор» по четным числам в массиве
        std::vector<DynamicObject*>& vecDynamicObj_;
        int curIndex;
        DynamicObject** ptr;
    public:
        BombIterator(std::vector<DynamicObject*>& ref) : vecDynamicObj_(ref), curIndex(-1), ptr(nullptr) { ++(*this); }
        void reset() { curIndex = -1; ptr = nullptr; }
        BombIterator& operator++ (); // префиксный инкремент
        BombIterator& operator++ (int); // постфиксный инкремент
        BombIterator& operator-- (); // префексный декремент
        BombIterator& operator-- (int); // постфиксный декремент
       
        DynamicObject* operator*(); // операция разыменования итератора
        
        bool operator==(BombIterator it); // проверка на лог. равенство итераторов
        bool operator!=(BombIterator it); // проверка на лог. неравенство
    };
private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
    std::shared_ptr<MyTools::ILogger> logger_;
};


// получаем итератор настроенный на начало массива
BombIterator begin() { BombIterator it(arr); return it; }
// итератор в конечном состоянии
BombIterator end() { BombIterator it(arr); it.reset(); return it; }
};