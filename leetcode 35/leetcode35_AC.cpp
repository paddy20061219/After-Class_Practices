#include <iostream>
#include <vector>
using namespace std;

// LeetCode 35 - Search Insert Position
// Correct version

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        // 找第一個 >= target 的位置
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};
