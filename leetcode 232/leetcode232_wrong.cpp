#include <iostream>
#include <stack>
using namespace std;

// LeetCode 232 - Implement Queue using Stacks
// Wrong version: this code is intentionally incorrect.

class MyQueue {
private:
    stack<int> st;

public:
    MyQueue() {
    }

    void push(int x) {
        st.push(x);
    }

    int pop() {
        // 錯誤想法：直接從 stack 最上面拿出來
        // 但 stack 是後進先出，queue 應該是先進先出。
        int value = st.top();
        st.pop();
        return value;
    }

    int peek() {
        return st.top();
    }

    bool empty() {
        return st.empty();
    }
};
