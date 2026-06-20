#include <iostream>
#include <string>
using namespace std;

// LeetCode 670 - Maximum Swap
// Correct version

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int last[10];

        // 紀錄每個數字最後一次出現的位置
        for (int i = 0; i < 10; i++) {
            last[i] = -1;
        }

        for (int i = 0; i < s.length(); i++) {
            last[s[i] - '0'] = i;
        }

        // 從左到右找，看能不能用右邊更大的數字來交換
        for (int i = 0; i < s.length(); i++) {
            int currentDigit = s[i] - '0';

            for (int d = 9; d > currentDigit; d--) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return stoi(s);
                }
            }
        }

        return num;
    }
};
