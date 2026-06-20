#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 31 - Next Permutation
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 錯誤想法：直接把整個陣列排序成由小到大
        // 但題目要求的是「下一個字典序排列」，不是最小排列。
        sort(nums.begin(), nums.end());
    }
};
