#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 31 - Next Permutation
// Correct version

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // 1. 從右往左找第一個 nums[i] < nums[i + 1] 的位置
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // 2. 如果有找到，從右邊找第一個比 nums[i] 大的數字並交換
        if (i >= 0) {
            int j = n - 1;

            while (nums[j] <= nums[i]) {
                j--;
            }

            swap(nums[i], nums[j]);
        }

        // 3. 把 i 後面的部分反轉，變成最小排列
        reverse(nums.begin() + i + 1, nums.end());
    }
};
