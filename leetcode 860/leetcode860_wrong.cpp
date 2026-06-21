#include <iostream>
#include <vector>
using namespace std;

// LeetCode 860 - Lemonade Change
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // 蠢錯誤：直接說一定可以找錢
        // 但如果一開始客人拿 10 或 20，就可能根本沒錢找。
        return true;
    }
};
