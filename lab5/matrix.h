#pragma once
#include <string>
using namespace std;

class IndexException
{
private:
	string m_error;

public:
	IndexException(std::string error)
		: m_error(error)
	{
	}

	const char* getError();
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

