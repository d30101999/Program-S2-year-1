#include <iostream>
#include <vector>
#include "functions.h"
#include "Cpoint.h"
using namespace std;


int main() {
	int arr[6] = { 2, 2, 88, 4, 2, 8 };
	vector<int> vec(arr, arr + 6);

	int arr_2[6] = { 2, 1, 1, 55, 43, 679 };
	vector<int> vec_2(arr_2, arr_2 + 6);

	int arr_3[6] = { 2, 2, 1, 55, 43, 679 };
	vector<int> vec_3(arr_3, arr_3 + 6);


	bool result = all_of(vec.begin(), vec.end(), DividedByTwo<int>());
	cout << "Result for first vector of ints (all_of) = " << result << endl;

	result = one_of(vec.begin(), vec.end(), DividedByTwo<int>());
	cout << "Result for first vector of ints (one_of) = " << result << endl;

	result = all_of(vec_2.begin(), vec_2.end(), DividedByTwo<int>());
	cout << "Result for second vector of ints (all_of) = " << result << endl;

	result = one_of(vec_2.begin(), vec_2.end(), DividedByTwo<int>());
	cout << "Result for second vector of ints (one_of) = " << result << endl;

	result = one_of(vec_3.begin(), vec_3.end(), DividedByTwo<int>());
	cout << "Result for third vector of ints (one_of) = " << result << endl;

	cout << "Found element for first vector of ints = " << *find_backward(vec.begin(), vec.end(), DividedByTwo<int>()) << endl;
	cout << "Found element for third vector of ints = " << *find_backward(vec_3.begin(), vec_3.end(), DividedByTwo<int>()) << endl;
	cout << "Found element for third vector of ints by value = " << *find_backward_by_value(vec_3.begin(), vec_3.end(), 2) << endl;

	cout << endl << "--------------" << endl;


	vector<CPoint> points_vec;
	for (int i = 0; i < 3; i++) {
		CPoint c(i, i);
		points_vec.push_back(c);
	}

	vector<CPoint> points_vec_2;
	for (int i = 0; i < 3; i++) {
		CPoint c(i, i + 1);
		points_vec_2.push_back(c);
	}


	result = all_of(points_vec.begin(), points_vec.end(), DividedByTwo<CPoint>());
	cout << "Result for first vector of CPoints (all_of) = " << result << endl;

	result = one_of(points_vec.begin(), points_vec.end(), DividedByTwo<CPoint>());
	cout << "Result for first vector of CPoints (one_of) = " << result << endl;

	result = all_of(points_vec_2.begin(), points_vec_2.end(), DividedByTwo<CPoint>());
	cout << "Result for second vector of CPoints (all_of) = " << result << endl;

	result = one_of(points_vec_2.begin(), points_vec_2.end(), DividedByTwo<CPoint>());
	cout << "Result for second vector of CPoints (one_of) = " << result << endl;

	vector<CPoint>::iterator found_element_cpoint = find_backward(points_vec.begin(), points_vec.end(), DividedByTwo<CPoint>());
	cout << "Found element for first vector of CPoints = " << *found_element_cpoint << endl;
	found_element_cpoint = find_backward(points_vec_2.begin(), points_vec_2.end(), DividedByTwo<CPoint>());
	cout << "Found element for second vector of CPoints = " << *found_element_cpoint << endl;
	CPoint c(1, 2);
	found_element_cpoint = find_backward_by_value(points_vec_2.begin(), points_vec_2.end(), c);
	cout << "Found element for second vector of CPoints by value = " << *found_element_cpoint << endl;


	return 0;
}
