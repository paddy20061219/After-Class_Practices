#include <iostream>
using namespace std;

// LeetCode 326 - Power of Three
// Correct version

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }

        // 不斷除以 3
        while (n % 3 == 0) {
            n /= 3;
        }

        // 如果最後變成 1，代表原本是 3 的次方
        return n == 1;
    }
};
