#include <iostream>
#include <vector>
using namespace std;

// LeetCode 641 - Design Circular Deque
// Wrong version: this code is intentionally incorrect.

class MyCircularDeque {
private:
    vector<int> data;
    int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
    }

    bool insertFront(int value) {
        // 錯誤做法：用 vector insert 模擬插入前端
        // 這不是 circular deque 的真正做法，而且會搬動很多元素。
        if (data.size() == capacity) {
            return false;
        }

        data.insert(data.begin(), value);
        return true;
    }

    bool insertLast(int value) {
        if (data.size() == capacity) {
            return false;
        }

        data.push_back(value);
        return true;
    }

    bool deleteFront() {
        if (data.empty()) {
            return false;
        }

        data.erase(data.begin());
        return true;
    }

    bool deleteLast() {
        if (data.empty()) {
            return false;
        }

        data.pop_back();
        return true;
    }

    int getFront() {
        if (data.empty()) {
            return -1;
        }

        return data[0];
    }

    int getRear() {
        if (data.empty()) {
            return -1;
        }

        return data[data.size() - 1];
    }

    bool isEmpty() {
        return data.empty();
    }

    bool isFull() {
        return data.size() == capacity;
    }
};
