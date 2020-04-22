#include "parallelogram.h"

double Parallelogram::area() {
    double length = sqrt((point1.x - point2.x) * (point1.x - point2.x)
                         + (point1.y - point2.y) * (point1.y - point2.y));
    double height = sqrt((point3.x - pointH.x) * (point3.x - pointH.x)
                        + (point3.x - pointH.y) * (point3.y - pointH.y));
    return length * height;
}

double Parallelogram::perimeter() {
    double length = sqrt((point1.x - point2.x) * (point1.x - point2.x)
                         + (point1.y - point2.y) * (point1.y - point2.y));
    double width = sqrt((point3.x - point2.x) * (point3.x - point2.x)
                        + (point3.y - point2.y) * (point3.y - point2.y));
    return 2 * (length + width);
}

double Parallelogram::mass() const {
    return mas;
}

CVector2D Parallelogram::position() {
    CVector2D pos{};
    pos.x = (point1.x + point3.x) / 2;
    pos.y = (point1.y + point3.y) / 2;
    return pos;
}

bool Parallelogram::operator== (const IPhysObject &ob) {
    return this->mass() == ob.mass();
}

bool Parallelogram::operator< (const IPhysObject &ob) {
    return this->mass() < ob.mass();
}

void Parallelogram::draw() {
    std::cout << "Point1: (" << point1.x <<", " << point1.y << ")" << std::endl;
    std::cout << "Point2: (" << point2.x <<", " << point2.y << ")" << std::endl;
    std::cout << "Point3: (" << point3.x <<", " << point3.y << ")" << std::endl;
    std::cout << "PointH: (" << pointH.x <<", " << pointH.y << ")" << std::endl;
    std::cout << "Area: " << area() << std::endl;
    std::cout << "Perimeter: " << perimeter() << std::endl;
    std::cout << "Mass: " << mass() << std::endl;
    std::cout << "Size in Memory: " << size() << std::endl;
}

void Parallelogram::initFromDialog() {
    std::cout << "Enter x and y respectively of the first point: \n";
    std::cin >> point1.x >> point1.y;
    std::cout << "Enter x and y respectively of the second point: \n";
    std::cin >> point2.x >> point2.y;
    std::cout << "Enter x and y respectively of the third point: \n";
    std::cin >> point3.x >> point3.y;
    std::cout << "Enter x and y respectively of the Height point: \n";
    std::cin >> pointH.x >> pointH.y;
    std::cout << "Enter the mass of the Parallelogram: \n";
    std::cin >> mas;
}

const char * Parallelogram::classname() {
    return "Parallelogram";
}

unsigned int Parallelogram::size() {
    return sizeof(Parallelogram);
}

/// *** Start of Set Functions *** ///

ParallelogramSet::ParallelogramSet() {
    size = 0;
}

void ParallelogramSet::add(Parallelogram *para) {
    set[size++] = para;
}

void ParallelogramSet::displaySet() {
    for(int i = 0; i < size; i++)
        set[i]->draw();
}

double ParallelogramSet::areaSum() {
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += set[i]->area();
    }
    return sum;
}

double ParallelogramSet::perimeterSum() {
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += set[i]->perimeter();
    }
    return sum;
}

double ParallelogramSet::sizeSum() {
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += set[i]->size();
    }
    return sum;
}

CVector2D ParallelogramSet::totalPosition() {
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

void ParallelogramSet::swap(Parallelogram& a, Parallelogram& b) {
    Parallelogram temp = a;
    a = b;
    b = temp;
}
void ParallelogramSet::sortByMass() {
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
