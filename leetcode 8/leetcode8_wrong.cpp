#include <iostream>
#include <string>
using namespace std;

// LeetCode 8 - String to Integer (atoi)
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;

        // 錯誤想法：看到數字就直接累加，完全不處理空白、正負號、溢位
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + (s[i] - '0');
            }
        }

        return ans;
    }
};
