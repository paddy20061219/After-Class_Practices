#include <iostream>
#include <vector>
using namespace std;

// LeetCode 303 - Range Sum Query - Immutable
// Correct version

class NumArray {
private:
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);

        // prefix[i + 1] 代表 nums[0] 到 nums[i] 的總和
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        // nums[left] 到 nums[right] 的總和
        return prefix[right + 1] - prefix[left];
    }
};
