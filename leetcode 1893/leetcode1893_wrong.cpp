#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1893 - Check if All the Integers in a Range Are Covered
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        // 蠢錯誤：完全不檢查 ranges
        // 直接說全部都有被 covered，這很明顯會錯。
        return true;
    }
};
