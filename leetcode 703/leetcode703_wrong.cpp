#include <iostream>
#include <vector>
using namespace std;

// LeetCode 703 - Kth Largest Element in a Stream
// wrong version: this code is intentionally very wrong.

class KthLargest {
private:
    int kValue;
    vector<int> nums;

public:
    KthLargest(int k, vector<int>& nums) {
        kValue = k;
        this->nums = nums;
    }

    int add(int val) {
        nums.push_back(val);

        // 蠢錯誤：直接回傳最新加入的數字
        // 題目要的是目前第 k 大，不是剛加入的 val。
        return val;
    }
};
