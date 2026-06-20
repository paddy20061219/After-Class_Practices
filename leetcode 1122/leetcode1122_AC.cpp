#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// LeetCode 1122 - Relative Sort Array
// Correct version

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> count;

        // 統計 arr1 中每個數字出現幾次
        for (int num : arr1) {
            count[num]++;
        }

        vector<int> ans;

        // 先依照 arr2 的順序放入答案
        for (int num : arr2) {
            while (count[num] > 0) {
                ans.push_back(num);
                count[num]--;
            }
        }

        vector<int> rest;

        // 把沒有出現在 arr2 的數字收集起來
        for (auto item : count) {
            int num = item.first;
            int times = item.second;

            while (times > 0) {
                rest.push_back(num);
                times--;
            }
        }

        // 剩下的數字要由小到大排序
        sort(rest.begin(), rest.end());

        for (int num : rest) {
            ans.push_back(num);
        }

        return ans;
    }
};
