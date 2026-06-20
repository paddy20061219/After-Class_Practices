#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// LeetCode 150 - Evaluate Reverse Polish Notation
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                // 錯誤想法：直接用 a - b、a / b
                // 但 RPN 中先 pop 出來的是右運算元，順序不能亂。
                if (token == "+") {
                    st.push(a + b);
                } else if (token == "-") {
                    st.push(a - b);
                } else if (token == "*") {
                    st.push(a * b);
                } else {
                    st.push(a / b);
                }
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
