#include <iostream>
#include <string>
using namespace std;

// LeetCode 125 - Valid Palindrome
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        // 錯誤想法：直接比較左右字元，沒有忽略符號，也沒有處理大小寫
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
