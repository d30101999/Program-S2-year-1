#include <iostream>
#include "function.h"
using namespace std;

int main(int argc, const char * argv[]) {
    write_interface();
    multinomial_interface interf;
    while(1) {
        int c = 0;
        cin >> c;
        switch (c) {
            case 1: {
                cout << "Enter a, b and c." << endl;
                int n = interf.solvingnumber();
                cout << "Multinomial has " << n << " solutions" << endl << endl << endl << endl;
                break;
            }
            case 2:{
                cout << "Enter a, b and c." << endl;
                double x1, x2;
                interf.solutions(x1, x2);
                break;
            }
            case 3:{
                double x;
                cout << "Enter the point:" << endl << "x = ";
                cin >> x;
                cout << "Enter a, b and c." << endl;
                double y = interf.valuepnt(x);
                cout << "When x = "<< x << " value of multinomial is " << y << endl << endl << endl << endl;
                break;
            }
            case 4:{
                cout << "Enter a, b and c." << endl;
                double min = 0;
                if (interf.min_(min) == 1) {
                    cout << "Minimum is " << min << endl << endl << endl << endl;
                }
                break;
            }
            case 5:{
                cout << "Enter a, b and c." << endl;
                double max;
                if (interf.max_(max) == 1) {
                    cout << "Maximum is " << max << endl << endl << endl << endl;
                }
                break;
            }
            case 6:{
                cout << "Enter a, b and c." << endl;
                interf.Display();
                break;
            }
            case 7:{
                cout << "Enter a, b and c." << endl;
                interf.Allatonce();
                break;
            }
            default:
                cout << "Not correct input!" << endl << endl << endl;
                break;
        }
        write_interface();
    }
    return 0;
}
