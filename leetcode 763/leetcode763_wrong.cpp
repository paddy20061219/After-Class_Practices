#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LeetCode 763 - Partition Labels
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;

        // 蠢錯誤：直接把整個字串當成一段
        // 題目要切成盡量多段，不是全部包在一起。
        ans.push_back(s.length());

        return ans;
    }
};
