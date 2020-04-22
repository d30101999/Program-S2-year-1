#include "interface.h"
#include "parallelogram.h"
#include "rectangle.h"

int main() {
    // *** Working with rectangles and sets of rectangles ***

    Rectangle rec1, rec2, rec3;
    std::cout << "=-=- Entering Data for the first rectangle -=-=" << std::endl;
    rec1.initFromDialog();
    std::cout << "\n=-=- Entering Data for the second rectangle -=-=" << std::endl;
    rec2.initFromDialog();
    std::cout << "\n=-=- Entering Data for the third rectangle -=-=" << std::endl;
    rec3.initFromDialog();


    RectangleSet recSet;
    recSet.add(&rec1);
    recSet.add(&rec2);
    recSet.add(&rec3);

    std::cout << "\n=-=- Printing all details of all rectangles -=-=" << std::endl;
    recSet.displaySet();
    std::cout << std::endl;
    std::cout << "Perimeter Sum: " << recSet.perimeterSum() << std::endl;
    std::cout << "Area Sum: " << recSet.areaSum() << std::endl;
    std::cout << "Size in memory sum: " << recSet.sizeSum() << std::endl;
    recSet.sortByMass();

    std::cout<< std::endl <<"************************************************"<< std::endl;




    //*** Working with segments and sets of parrallelogram ***
    Parallelogram para1, para2, para3;
    std::cout << "=-=- Entering Data for the first Parallelogram -=-=" << std::endl;
    para1.initFromDialog();
    std::cout << "\n=-=- Entering Data for the second Parallelogram -=-=" << std::endl;
    para2.initFromDialog();
    std::cout << "\n=-=- Entering Data for the third Parallelogram -=-=" << std::endl;
    para3.initFromDialog();



    ParallelogramSet paraSet;
    paraSet.add(&para1);
    paraSet.add(&para2);
    paraSet.add(&para3);

    std::cout << "\n=-=- Printing all details of all Parallelogram -=-=" << std::endl;
    paraSet.displaySet();
    std::cout << std::endl;
    std::cout << "Perimeter Sum: " << paraSet.perimeterSum() << std::endl;
    std::cout << "Area Sum: " << paraSet.areaSum() << std::endl;
    std::cout << "Size in memory sum: " << paraSet.sizeSum() << std::endl;
    paraSet.sortByMass();


    return 0;
}

