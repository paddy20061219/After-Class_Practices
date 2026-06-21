#include <iostream>
#include <vector>
using namespace std;

// LeetCode 63 - Unique Paths II
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // 蠢錯誤：完全不管障礙物
        // 直接回傳 m + n，這跟路徑數量其實沒關係。
        return m + n;
    }
};
