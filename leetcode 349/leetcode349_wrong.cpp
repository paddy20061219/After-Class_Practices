#include <iostream>
#include <vector>
using namespace std;

// LeetCode 349 - Intersection of Two Arrays
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        // 錯誤想法：只要兩個陣列中有相同數字就直接加入答案
        // 但題目要求答案不能有重複元素。
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    ans.push_back(nums1[i]);
                }
            }
        }

        return ans;
    }
};
