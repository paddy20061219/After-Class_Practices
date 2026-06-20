#include <iostream>
#include <vector>
using namespace std;

// LeetCode 622 - Design Circular Queue
// Wrong version: this code is intentionally incorrect.

class MyCircularQueue {
private:
    vector<int> data;
    int capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
    }

    bool enQueue(int value) {
        // 錯誤想法：只要 vector 還沒滿就 push_back
        // 但沒有真正做 circular queue，也沒有重複利用前面空出來的位置。
        if (data.size() == capacity) {
            return false;
        }

        data.push_back(value);
        return true;
    }

    bool deQueue() {
        if (data.empty()) {
            return false;
        }

        // 錯誤做法：直接刪除第一個元素
        // erase 不是 circular queue 的做法，而且效率也不好。
        data.erase(data.begin());
        return true;
    }

    int Front() {
        if (data.empty()) {
            return -1;
        }

        return data[0];
    }

    int Rear() {
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
