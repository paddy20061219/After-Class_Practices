#include <iostream>
#include <vector>
using namespace std;

// LeetCode 622 - Design Circular Queue
// Correct version

class MyCircularQueue {
private:
    vector<int> data;
    int frontIndex;
    int rearIndex;
    int currentSize;
    int capacity;

public:
    MyCircularQueue(int k) {
        data.resize(k);
        capacity = k;
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        rearIndex = (rearIndex + 1) % capacity;
        data[rearIndex] = value;
        currentSize++;

        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;

        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return data[frontIndex];
    }

    int Rear() {
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
