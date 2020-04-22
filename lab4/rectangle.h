#pragma once

#include "interface.h"

class Rectangle: public IGeoFig, IPhysObject, IPrintable, IDialogInitiable, BaseCObject {
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
    CVector2D point1{}, point2{}, point3{}; ///just need 3 points to calculate
    double mas{};
};

class RectangleSet {
public:
    RectangleSet();
    void add(Rectangle *rec);
    void displaySet();
    double areaSum();
    double perimeterSum();
    double sizeSum();
    CVector2D totalPosition();
    void swap(Rectangle& a, Rectangle& b);
    void sortByMass();
private:
    Rectangle *set[100]{};
    int size;
};
