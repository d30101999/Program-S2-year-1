#include "CircularBuffer.h"

int main() {
    CircularBuffer<int> Buffer(10);
    Buffer.push_top(100);
    Buffer.push_back(25);
    Buffer.push_top(33);
    Buffer.push_back(4);
    Buffer.push_back(55);
    Buffer.push_back(6);
    Buffer.push_top(7);
    Buffer.push_back(8);
    Buffer.push_top(9);
    Buffer.push_top(10);
    ///Buffer[0] = 150;
    std::cout << "CircularBuffer with Capacity = 10" << std::endl;

    for (int i : Buffer) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "Delete 9" << std::endl;
    Buffer.erase(find(Buffer.begin(), Buffer.end(), 9));
    for (int i : Buffer) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "Delete 33" << std::endl;
    Buffer.erase(find(Buffer.begin(), Buffer.end(), 33));
    for (int i : Buffer) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "Insert 1111 at place of 6" << std::endl;
    Buffer.insert(find(Buffer.begin(), Buffer.end(), Buffer[5]), 1111);
    for (int i : Buffer) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "Change to Capacity = 5" << std::endl;
    Buffer.resize(5);
    for (int i : Buffer) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "Sort" << std::endl;
    sort(Buffer.begin(), Buffer.end());
    for (int i : Buffer) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "Push top 228" << std::endl;
    Buffer.push_top(228);
    for (int i : Buffer) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "Pop top" << std::endl;
    Buffer.pop_top();
    for (int i : Buffer) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "Push back 1337" << std::endl;
    Buffer.push_back(1337);
    for (int i : Buffer) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "Pop back" << std::endl;
    Buffer.pop_back();
    for (int i : Buffer) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    return 0;
}
