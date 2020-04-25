#include <iostream>
#include <string>
#include "value.h"
#include "matrix.h"
using namespace std;


int main() {
	// class:
	MMassive<2, 3, float> matrix;
	try {
		matrix[0][1] = 3.2;
	}
	catch (IndexException & exception) {
		cerr << "An index exception occurred (" << exception.getError() << ")" << endl;
	}

	try {
		cout << matrix[0][1] << endl;
	}
	catch (IndexException & exception) {
		cerr << "An index exception occurred (" << exception.getError() << ")" << endl;
	}

	try {
		cout << matrix[0][5] << endl;
	}
	catch (IndexException & exception) {
		cerr << "An index exception occurred (" << exception.getError() << ")" << endl;
	}

	// function
	cout << ownPower<float, 3>(5) << endl;
	return 0;
}