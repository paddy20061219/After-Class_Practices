#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// LeetCode 125 - Valid Palindrome
// Correct version

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // 跳過左邊不是英文字母或數字的字元
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // 跳過右邊不是英文字母或數字的字元
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // 比較時要忽略大小寫
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
