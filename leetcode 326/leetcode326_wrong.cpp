#include <iostream>
using namespace std;

// LeetCode 326 - Power of Three
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    bool isPowerOfThree(int n) {
        // 錯誤想法：只要可以被 3 整除，就當成 3 的次方
        if (n <= 0) {
            return false;
        }

        return n % 3 == 0;
    }
};
