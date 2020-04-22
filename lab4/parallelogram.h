#pragma once

#include "interface.h"

class Parallelogram: public IGeoFig, IPhysObject, IPrintable, IDialogInitiable, BaseCObject {
public:
    double area() override;
    double perimeter() override;
    double mass() const override;
    CVector2D position() override;
    bool operator== (const IPhysObject& ob) override;
    bool operator< (const IPhysObject& ob) override;
    void draw() override;
    void initFromDialog() override;
    const char * classname() override;
    unsigned int size() override;
private:
    CVector2D point1{}, point2{}, point3{},pointH;  ///just need 3 points and the point of height to calculate
    double mas{};
};

class ParallelogramSet {
public:
    ParallelogramSet();
    void add(Parallelogram *rec);
    void displaySet();
    double areaSum();
    double perimeterSum();
    double sizeSum();
    CVector2D totalPosition();
    void swap(Parallelogram& a, Parallelogram& b);
    void sortByMass();
private:
    Parallelogram *set[100]{};
    int size;
};
