#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 378 - Kth Smallest Element in a Sorted Matrix
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;

        // 錯誤想法：只把第一列拿出來排序
        // 但答案可能在其他列裡面。
        for (int j = 0; j < matrix[0].size(); j++) {
            nums.push_back(matrix[0][j]);
        }

        sort(nums.begin(), nums.end());

        return nums[k - 1];
    }
};
