#include <iostream>
#include <vector>
using namespace std;

// LeetCode 303 - Range Sum Query - Immutable
// Wrong version: this code is intentionally incorrect.

class NumArray {
private:
    vector<int> nums;

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }

    int sumRange(int left, int right) {
        int sum = 0;

        // 錯誤想法：只算到 right 前一個位置
        // 但題目要求 left 到 right 都要包含。
        for (int i = left; i < right; i++) {
            sum += nums[i];
        }

        return sum;
    }
};
