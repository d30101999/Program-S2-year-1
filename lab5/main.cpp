#include <iostream>
#include <string>
using namespace std;

template < typename T, size_t Power >
T ownPower(T element) {
	T multiplier = element;
	if (Power == 0) {
		element = 1;
	}
	else if (Power > 0) {
		for (int i = 0; i < Power - 1; i++) {
			element *= multiplier;
		}
	}
	else {
		for (int i = 0; i < Power - 1; i++) {
			element *= multiplier;
		}
		return 1.0 / element;
	}
	return element;
}

class IndexException
{
private:
	string m_error;

public:
	IndexException(std::string error)
		: m_error(error)
	{
	}

	const char* getError() { return m_error.c_str(); }
};


template <size_t N, size_t M, class T>
class MMassive
{
private:
	class submas;
	int row, col;
	submas* arr;
	class submas
	{
	public:
		T* sarr;

		submas() {}
		submas(int size)
		{
			sarr = new T[size];
			for (int i = 0; i < size; i++)
			{
				sarr[i] = 0;
			}
		}
		T& operator [] (int i)
		{
			if (i < 0 || i >= M)
				throw IndexException("Invalid index");
			return sarr[i];
		}
	};

public:
	MMassive()
	{
		N < 1 ? row = 1 : row = N;
		M < 1 ? col = 1 : col = M;

		arr = new submas[row];
		for (int i = 0; i < row; i++)
		{
			arr[i] = submas(col);
		}
	}
	submas& operator [] (int i)
	{
		if (i < 0 || i >= N)
			throw IndexException("Invalid index");
		return arr[i];
	}

	~MMassive()
	{
		for (int i = 0; i < row; i++)
		{
			if (arr[i].sarr != nullptr)
				delete[](arr[i].sarr);
		}
		if (arr != nullptr)
			delete[] arr;
	}
};

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
	cout << ownPower<float, 3 >(5) << endl;
	return 0;
}
