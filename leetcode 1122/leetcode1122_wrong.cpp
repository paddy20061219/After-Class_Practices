#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 1122 - Relative Sort Array
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // 錯誤想法：直接把 arr1 由小到大排序
        // 但題目要求要依照 arr2 的相對順序排列。
        sort(arr1.begin(), arr1.end());

        return arr1;
    }
};
