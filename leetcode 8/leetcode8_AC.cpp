#include <iostream>
#include <string>
#include <climits>
using namespace std;

// LeetCode 8 - String to Integer (atoi)
// Correct version

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();

        // 1. 跳過前面的空白
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. 判斷正負號
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // 3. 讀取數字，並檢查是否超過 int 範圍
        long long ans = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');

            if (sign == 1 && ans > INT_MAX) {
                return INT_MAX;
            }

            if (sign == -1 && -ans < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return sign * ans;
    }
};
