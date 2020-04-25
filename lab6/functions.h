#pragma once
#include "functions.h"

template < typename ForwardIterator, typename T >
bool all_of(ForwardIterator first, ForwardIterator last, T pred) {
	for (; first != last; ++first)
		if (!pred(*first))
			return false;
	return true;
}

template < typename ForwardIterator, typename T >
bool one_of(ForwardIterator first, ForwardIterator last, T pred) {
	bool flag = false;
	for (; first != last; ++first)
		if (pred(*first) && !flag)
			flag = true;
		else if (pred(*first))
			return false;
	return flag == true;
}

template < typename ForwardIterator, typename T>
ForwardIterator find_backward(ForwardIterator first, ForwardIterator last, T pred) {
	--last;
	for (; first != last; --last) {
		if (pred(*last)) {
			return last;
		}
	}
	return first;
}

template < typename ForwardIterator, typename T>
ForwardIterator find_backward_by_value(ForwardIterator first, ForwardIterator last, T value) {
	--last;
	for (; first != last; --last)
		if (value == (*last))
			return last;
	return first;
}


template < typename T >
class DividedByTwo
{
public:
	bool operator()(const T x) const
	{
		return x % 2 == 0;
	}
};

