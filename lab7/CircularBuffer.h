#ifndef CIRCULARBUFFER_H_INCLUDED
#define CIRCULARBUFFER_H_INCLUDED

#include "Iterator.h"

template <typename T>
class CircularBuffer {
public:
    CircularBuffer(size_t _capacity) {
        element = new T[_capacity + 1];
        capacity = _capacity + 1;
        start = 0;
        _end = 0;
        count = 0;
    }

    Iterator<T> begin() {
        Iterator<T> iterator(element, capacity, start, _end, start);
        return iterator;
    }

    Iterator<T> end() {
        Iterator<T> iterator(element, capacity, start, _end, _end);
        return iterator;
    }

    void push_back(const T& val) {
        if (start % capacity - _end % capacity == 1) {
            start = (start + 1) % capacity;
        }
        else {
            count++;
        }
        element[_end % capacity] = val;
        _end = (_end + 1) % capacity;
    }

    void push_top(const T& val) {
        if (_end % capacity - start % capacity == 1 || (_end == capacity - 1 && start == 0)) {
            _end = (_end + capacity - 1) % capacity;
        }
        else {
            count++;
        }
        start = (start + capacity - 1) % capacity;
        element[start % capacity] = val;
    }

    void pop_back() {
        if (start % capacity != _end % capacity) {
            _end = (_end + capacity - 1) % capacity, count--;
        }
        else {
            std::cerr << "Buffer is empty";
        }
    }

    void pop_top() {
        if (start % capacity != _end % capacity) {
            start = (start + 1) % capacity, count--;
        }
        else {
            std::cerr << "Buffer is empty";
        }
    }

    Iterator<T> insert(const Iterator<T>& iterator, const T& value) {
        if (iterator == begin()) {
            push_top(value);
            return begin();
        }
        else if (iterator == end()) {
            push_back(value);
            return end() - 1;
        }
        else {
            T* buffer = new T[capacity];
            int max_size = 0;
            int position_in_buffer = -1;
            int i = 0;
            for (auto it = begin(); it != end(), i <= count; it++, i++) {
                if (it == iterator) {
                    position_in_buffer = i;
                    buffer[i] = value;
                    max_size++;
                    i++;
                }
                buffer[i] = *it;
                max_size++;
            }
            delete[] element;
            element = new T[capacity];
            for (int i = 0; i <= max_size; i++) {
                element[i] = buffer[i];
            }
            start = 0;
            _end = max_size;
            count = max_size;
            delete[] buffer;
            return begin() + position_in_buffer;
        }
    }

    Iterator<T> erase(const Iterator<T>& iterator) {
        if (iterator == begin()) {
            pop_top();
            return begin();
        }
        else if (iterator == end() - 1) {
            pop_back();
            return end() - 1;
        }
        else {
            T* buffer = new T[capacity];
            int max_size = 0;
            int position_in_buffer = -1;
            int i = 0;
            for (auto it = begin(); it != end(); it++, i++) {
                if (it == iterator) {
                    position_in_buffer = i;
                    it++;
                }
                buffer[i] = *it;
                max_size = i;
            }
            delete[] element;
            element = new T[capacity];
            for (int i = 0; i <= max_size; i++) {
                element[i] = buffer[i];
            }
            start = 0;
            _end = max_size + 1;
            count = max_size + 1;
            delete[] buffer;
            return begin() + position_in_buffer;
        }
    }

    void resize(const size_t & _capacity) {
        T* buffer = new T[capacity];
        int max_size = 0;
        for (int i = 0; i < _capacity; i++) {
            if (i == count) {
                break;
            }
            buffer[i] = operator[](i);
            max_size++;
        }
        delete[] element;
        element = new T[_capacity + 1];
        for (int i = 0; i < max_size; i++) {
            element[i] = buffer[i];
        }
        count = max_size;
        capacity = _capacity + 1;
        start = 0;
        _end = count;
        delete[] buffer;
    }

    size_t size() const {
        return count;
    }

    T& operator[] (const size_t & i) const {
        return element[(start + i) % capacity];
    }

    ~CircularBuffer() {
        delete[] element;
    }

private:
    size_t capacity;
    size_t count;
    int start;
    int _end;
    T* element;
};


#endif // CIRCULARBUFFER_H_INCLUDED
