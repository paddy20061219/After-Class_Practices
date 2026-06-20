#include <iostream>
#include <vector>
using namespace std;

// LeetCode 35 - Search Insert Position
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 錯誤想法：只找 target 有沒有出現
        // 如果沒找到就回傳 -1，但題目要求回傳應該插入的位置。
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }

        return -1;
    }
};
