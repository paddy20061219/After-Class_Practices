#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// LeetCode 349 - Intersection of Two Arrays
// Correct version

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> resultSet;

        // 先把 nums1 的元素放進 set
        for (int num : nums1) {
            set1.insert(num);
        }

        // 檢查 nums2 的元素是否也出現在 nums1
        for (int num : nums2) {
            if (set1.count(num)) {
                resultSet.insert(num);
            }
        }

        vector<int> ans;
        for (int num : resultSet) {
            ans.push_back(num);
        }

        return ans;
    }
};
