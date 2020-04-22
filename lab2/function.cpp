#include "function.h"
#include <iostream>
#include <cmath>
using namespace std;

multinomial::multinomial() : a(1), b(1), c(1) {}

multinomial::multinomial(double a, double b, double c) {
    if (a == 0){
        cout << "Не верные данные(a != 0)" << endl; //Wrong data, information
        return;
    }
    this->a = a;
    this->b = b;
    this->c = c;
}

multinomial::multinomial(multinomial const& a) : a(a.a), b(a.b), c(a.c) {}

double multinomial::value_pnt(double x) { //take the value of x
    return (a * x * x + b * x + c);
}

int multinomial::solving_number() {
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0){
        return 2;
    } else if (discriminant == 0) {
        return 1;
    } else { return 0; }
}

void multinomial::solve(double &x1, double &x2) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0){
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
    } else if (discriminant == 0) {
        x1 = -b/(2*a);
        x2 = 999;
    } else {
        x1 = 999;
        x2 = 999;
    }
}

bool multinomial::minimum(double &min) {
    if(a < 0) {
        cout << "It doesn't have minimum!" << endl;
        return 0;
    }
    double x0 = -b/(2*a);
    min = (a*x0*x0 + b*x0 + c);
    return 1;
}

bool multinomial::maximum(double &max) {
    if(a > 0) {
        cout << "It doesn't have maximum!" << endl;
        return 0;
    }
    double x0 = -b/(2*a);
    max = (a*x0*x0 + b*x0 + c);
    return 1;
}

void multinomial::display() {
    cout << a << "x^2";
    if(b > 0) {
        cout << " + " << b << "x";
        if(c > 0) {
            cout << " + " << c << endl;
        } else if(c < 0) {
            cout << c << endl;
        } else cout << endl;
    } else if(b < 0) {
        cout << b << "x";
        if(c > 0) {
            cout << " + " << c << endl;
        } else if(c < 0) {
            cout << c << endl;
        } else cout << endl;
    } else {
        if(c > 0) {
            cout << " + " << c << endl;
        } else if(c < 0) {
            cout << c << endl;
        } else cout << endl;
    }
    cout << endl;
}

double multinomial::get_a() {return a;}

double multinomial::get_b() {return b;}

double multinomial::get_c() {return c;}

void multinomial::allatonce() {

}


double multinomial_interface::valuepnt(double x) {
    double a, b, c;
    cout << "a: ";
    cin >> a;
    cout << endl << "b: ";
    cin >> b;
    cout << endl << "c: ";
    cin >> c;
    cout << endl << "---------------------------------------------" << endl;
    multinomial mn(a, b, c);
    return mn.value_pnt(x);
}

int multinomial_interface::solvingnumber() {
    double a, b, c;
    cout << "a: ";
    cin >> a;
    cout << endl << "b: ";
    cin >> b;
    cout << endl << "c: ";
    cin >> c;
    cout << endl << "---------------------------------------------" << endl;
    multinomial mn(a, b, c);
    return mn.solving_number();
}

void multinomial_interface::solutions(double &x1, double &x2) {
    double a, b, c;
    cout << "a: ";
    cin >> a;
    cout << endl << "b: ";
    cin >> b;
    cout << endl << "c: ";
    cin >> c;
    cout << endl << "---------------------------------------------" << endl;
    multinomial mn(a, b, c);
    mn.solve(x1, x2);
    if (mn.solving_number() == 2) {
        cout << "Solutions: first is " << x1 << " and the second is " << x2 << endl << endl << endl << endl;
    } else if (mn.solving_number() == 1) {
        cout << "Solution is " << x1 << endl << endl << endl << endl;
    } else cout << "It doesn't have solutions" << endl << endl << endl << endl;
}

bool multinomial_interface::min_(double &min) {
    double a, b, c;
    cout << "a: ";
    cin >> a;
    cout << endl << "b: ";
    cin >> b;
    cout << endl << "c: ";
    cin >> c;
    cout << endl << "---------------------------------------------" << endl;
    multinomial mn(a, b, c);
    return mn.minimum(min);
}

bool multinomial_interface::max_(double &max) {
    double a, b, c;
    cout << "a: ";
    cin >> a;
    cout << endl << "b: ";
    cin >> b;
    cout << endl << "c: ";
    cin >> c;
    cout << endl << "---------------------------------------------" << endl;
    multinomial mn(a, b, c);
    return mn.maximum(max);
}

void multinomial_interface::Display() {
    double a, b, c;
    cout << "a: ";
    cin >> a;
    cout << endl << "b: ";
    cin >> b;
    cout << endl << "c: ";
    cin >> c;
    cout << endl << "---------------------------------------------" << endl;
    multinomial mn(a, b, c);
    mn.display();
}

void multinomial_interface::Allatonce() {
    double a, b, c;
    cout << "a: ";
    cin >> a;
    cout << endl << "b: ";
    cin >> b;
    cout << endl << "c: ";
    cin >> c;
    cout << endl << "---------------------------------------------" << endl;
    multinomial mn(a, b, c);

    cout << endl << "1) You entered this multinomial: ";
    mn.display();

    int n = mn.solving_number();
    if (n != 0){
        cout << "2) It has " << mn.solving_number() << " solutions" << endl << endl;
    }

    double x1, x2;
    mn.solve(x1, x2);
    if (mn.solving_number() == 2) {
        cout << "3) Solutions: first is " << x1 << " and the second is " << x2 << endl << endl;
    } else if (mn.solving_number() == 1) {
        cout << "3) Solution is " << x1 << endl << endl;
    } else cout << "2) It doesn't have solutions" << endl << endl;

    if (n == 0) {
        cout << "3) ";
        double max;
        if (mn.maximum(max) == 1) {
            cout << "Maximum is " << max << endl << endl;
        } else cout << endl;

        cout << "4) ";
        double min;
        if (mn.minimum(min) == 1) {
            cout << "Minimum is " << max << endl << endl;
        } else cout << endl;
    } else {
        cout << "4) ";
        double max;
        if (mn.maximum(max) == 1) {
            cout << "Maximum is " << max << endl << endl;
        } else cout << endl;

        cout << "5) ";
        double min;
        if (mn.minimum(min) == 1) {
            cout << "Minimum is " << max << endl << endl;
        } else cout << endl;
    }
}







void write_interface() {
    cout << "                           Multinomial" << endl;
    cout << "               Press  1  to get the number of solutions" << endl;
    cout << "               Press  2  to solve" << endl;
    cout << "               Press  3  to get the value in the point" << endl;
    cout << "               Press  4  to find the minimum" << endl;
    cout << "               Press  5  to find the maximum" << endl;
    cout << "               Press  6  to display" << endl;
    cout << "               Press  7  to do all at once" << endl << endl << endl;
}
