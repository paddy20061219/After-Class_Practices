#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// LeetCode 670 - Maximum Swap
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);

        // 錯誤想法：直接把所有數字由大到小排序
        // 但題目只允許交換一次，不能任意重排全部數字。
        sort(s.begin(), s.end(), greater<char>());

        return stoi(s);
    }
};
