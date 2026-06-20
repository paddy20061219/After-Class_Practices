#include <iostream>
#include <vector>
using namespace std;

// LeetCode 641 - Design Circular Deque
// Correct version

class MyCircularDeque {
private:
    vector<int> data;
    int frontIndex;
    int rearIndex;
    int currentSize;
    int capacity;

public:
    MyCircularDeque(int k) {
        data.resize(k);
        capacity = k;
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = 0;
        } else {
            frontIndex = (frontIndex - 1 + capacity) % capacity;
        }

        data[frontIndex] = value;
        currentSize++;

        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = 0;
        } else {
            rearIndex = (rearIndex + 1) % capacity;
        }

        data[rearIndex] = value;
        currentSize++;

        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        if (currentSize == 1) {
            currentSize--;
            return true;
        }

        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;

        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        if (currentSize == 1) {
            currentSize--;
            return true;
        }

        rearIndex = (rearIndex - 1 + capacity) % capacity;
        currentSize--;

        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return data[frontIndex];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return data[rearIndex];
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == capacity;
    }
};
