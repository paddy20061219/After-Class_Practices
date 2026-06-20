#include <iostream>
#include <string>
using namespace std;

// LeetCode 6 - Zigzag Conversion
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";

        // 錯誤想法：直接把每 numRows 個字元分成一組，
        // 但這完全沒有處理 Zigzag 的斜線部分。
        for (int row = 0; row < numRows; row++) {
            for (int i = row; i < s.length(); i += numRows) {
                ans += s[i];
            }
        }

        return ans;
    }
};
