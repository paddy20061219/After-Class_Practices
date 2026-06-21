#include <iostream>
#include <vector>
using namespace std;

// LeetCode 435 - Non-overlapping Intervals
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 蠢錯誤：直接說不用刪任何 interval
        // 但如果區間有重疊，就一定可能需要刪掉一些。
        return 0;
    }
};
