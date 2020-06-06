#ifndef ITERATOR_H_INCLUDED
#define ITERATOR_H_INCLUDED

#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

template <typename T>
class Iterator : public std::iterator<std::random_access_iterator_tag, T> {
public:
    using difference_type = typename std::iterator<std::random_access_iterator_tag, T>::difference_type;
    Iterator(T* buffer, size_t & _capacity, int& _start, int& _end, int _position) {
        data = buffer;
        capacity = _capacity;
        start = _start;
        end = _end;
        position = _position;
    }

    bool operator!= (Iterator const& _other_iterator) const {
        return this->position % capacity != _other_iterator.position % capacity;
    }

    bool operator== (Iterator const& _other_iterator) const {
        return this->position % capacity == _other_iterator.position % capacity;
    }

    bool operator> (const Iterator& rhs) const {
        if (start > end) {
            if (position < capacity && rhs.position < capacity) {
                return position > rhs.position;
            }
            else if (position < capacity) {
                return false;
            }
            else if (rhs.position < capacity) {
                return true;
            }
            else {
                return position > rhs.position;
            }
        }
        else {
            return position > rhs.position;
        }
    }

    bool operator< (const Iterator& rhs) const {
        if (start > end) {
            if (position < capacity && rhs.position < capacity) {
                return position < rhs.position;
            }
            else if (position < capacity) {
                return true;
            }
            else if (rhs.position < capacity) {
                return false;
            }
            else {
                return position < rhs.position;
            }
        }
        else {
            return position < rhs.position;
        }
    }

    bool operator>= (const Iterator& rhs) const {
        if (start > end) {
            if (position < capacity && rhs.position < capacity) {
                return position >= rhs.position;
            }
            else if (position < capacity) {
                return false;
            }
            else if (rhs.position < capacity) {
                return true;
            }
            else {
                return position >= rhs.position;
            }
        }
        else
            return position >= rhs.position;
    }

    bool operator<= (const Iterator& rhs) const {
        if (start > end) {
            if (position < capacity && rhs.position < capacity) {
                return position <= rhs.position;
            }
            else if (position < capacity) {
                return true;
            }
            else if (rhs.position < capacity) {
                return false;
            }
            else {
                return position <= rhs.position;
            }
        }
        else {
            return position <= rhs.position;
        }
    }

    difference_type operator- (const Iterator& it) const {
        Iterator iterator = *this;
        iterator.position -= it.position;
        return *iterator;
    }

    difference_type operator+ (const Iterator& it) const {
        Iterator iterator = *this;
        iterator.position += it.position;
        return *iterator;
    }

    Iterator operator+ (const int& _pos) const {
        Iterator iterator = *this;
        iterator.position = (position + _pos) % capacity;
        return iterator;
    }

    Iterator operator- (const int& _pos) const {
        Iterator iterator = *this;
        iterator.position = (position + capacity - _pos) % capacity;
        return iterator;
    }

    Iterator operator++ () {
        this->position++;
        return *this;
    }

    Iterator operator++ (int) {
        Iterator tmp(*this);
        operator++ ();
        return tmp;
    }

    Iterator operator-- () {
        this->position--;
        return *this;
    }
    Iterator operator-- (int) {
        Iterator tmp(*this);
        operator-- ();
        return tmp;
    }

    typename Iterator::reference operator* () const {
        return data[position % capacity];
    }

private:
    T* data;
    int position;
    int start;
    int end;
    size_t capacity;
};


#endif // ITERATOR_H_INCLUDED
