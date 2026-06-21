#include <iostream>
#include <vector>
using namespace std;

// LeetCode 347 - Top K Frequent Elements
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        // 蠢錯誤：直接回傳前 k 個數字
        // 題目要的是出現次數最高的 k 個數字，不是陣列前 k 個。
        for(int i = 0; i < k && i < nums.size(); i++){
            ans.push_back(nums[i]);
        }

        return ans;
    }
};
