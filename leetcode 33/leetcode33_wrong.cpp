#include <iostream>
#include <vector>
using namespace std;

// LeetCode 33 - Search in Rotated Sorted Array
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // 錯誤想法：直接用普通 binary search
        // 但陣列被旋轉過，不一定整體由小到大排序。
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};
