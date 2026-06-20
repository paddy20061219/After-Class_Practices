#include <iostream>
#include <stack>
using namespace std;

// LeetCode 232 - Implement Queue using Stacks
// Correct version

class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

    void moveToOutStack() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() {
    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        moveToOutStack();

        int value = outStack.top();
        outStack.pop();

        return value;
    }

    int peek() {
        moveToOutStack();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
