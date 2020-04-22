#include "Rectangle.h"

double Rectangle::area() {
    double length = sqrt((point1.x - point2.x) * (point1.x - point2.x)
                         + (point1.y - point2.y) * (point1.y - point2.y));
    double width = sqrt((point3.x - point2.x) * (point3.x - point2.x)
                        + (point3.y - point2.y) * (point3.y - point2.y));
    return length * width;
}

double Rectangle::perimeter() {
    double length = sqrt((point1.x - point2.x) * (point1.x - point2.x)
                         + (point1.y - point2.y) * (point1.y - point2.y));
    double width = sqrt((point3.x - point2.x) * (point3.x - point2.x)
                        + (point3.y - point2.y) * (point3.y - point2.y));
    return 2 * (length + width);
}

double Rectangle::mass() const {
    return mas;
}

CVector2D Rectangle::position() {
    CVector2D pos{};
    pos.x = (point1.x + point3.x) / 2;
    pos.y = (point1.y + point3.y) / 2;
    return pos;
}

bool Rectangle::operator== (const IPhysObject &ob) {
    return this->mass() == ob.mass();
}

bool Rectangle::operator< (const IPhysObject &ob) {
    return this->mass() < ob.mass();
}

void Rectangle::draw() {
    std::cout << "Point1: (" << point1.x <<", " << point1.y << ")" << std::endl;
    std::cout << "Point2: (" << point2.x <<", " << point2.y << ")" << std::endl;
    std::cout << "Point3: (" << point3.x <<", " << point3.y << ")" << std::endl;
    std::cout << "Area: " << area() << std::endl;
    std::cout << "Perimeter: " << perimeter() << std::endl;
    std::cout << "Mass: " << mass() << std::endl;
    std::cout << "Size in Memory: " << size() << std::endl;
}

void Rectangle::initFromDialog() {
    std::cout << "Enter x and y respectively of the first point: \n";
    std::cin >> point1.x >> point1.y;
    std::cout << "Enter x and y respectively of the second point: \n";
    std::cin >> point2.x >> point2.y;
    std::cout << "Enter x and y respectively of the third point: \n";
    std::cin >> point3.x >> point3.y;
    std::cout << "Enter the mass of the rectangle: \n";
    std::cin >> mas;
}

const char * Rectangle::classname() {
    return "Rectangle";
}

unsigned int Rectangle::size() {
    return sizeof(Rectangle);
}

/// *** Start of Set Functions *** ///

RectangleSet::RectangleSet() {
    size = 0;
}

void RectangleSet::add(Rectangle *rec) {
    set[size++] = rec;
}

void RectangleSet::displaySet() {
    for(int i = 0; i < size; i++)
        set[i]->draw();
}

double RectangleSet::areaSum() {
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += set[i]->area();
    }
    return sum;
}

double RectangleSet::perimeterSum() {
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += set[i]->perimeter();
    }
    return sum;
}

double RectangleSet::sizeSum() {
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += set[i]->size();
    }
    return sum;
}

CVector2D RectangleSet::totalPosition() {
    CVector2D pos{};
    pos.x = 0;
    pos.y = 0;
    for(int i = 0; i < size; i++) {
        pos.x += set[i]->position().x;
        pos.y += set[i]->position().y;
    }
    pos.x /= size;
    pos.y /= size;
    return pos;
}

void RectangleSet::swap(Rectangle& a, Rectangle& b) {
    Rectangle temp = a;
    a = b;
    b = temp;
}
void RectangleSet::sortByMass() {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(set[j]->mass() > set[j + 1]->mass())
                swap(*set[j], *set[j + 1]);
        }
    }
    std::cout << "Sorted according to mass: " << std::endl;
    for(int i = 0; i < size; i++) {
        std::cout << set[i]->mass() <<" ";
    }
}
