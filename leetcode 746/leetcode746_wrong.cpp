#include <bits/stdc++.h>
using namespace std;

// LeetCode 746 - Min Cost Climbing Stairs
// 這個是故意寫錯的版本，想法太天真

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int even = 0;
        int odd = 0;

        // 我以為只要算偶數階跟奇數階哪邊比較便宜就好
        // 但其實每次可以走 1 或 2 階，不是只能固定踩奇數或偶數
        for (int i = 0; i < cost.size(); i++) {
            if (i % 2 == 0) {
                even += cost[i];
            } else {
                odd += cost[i];
            }
        }

        return min(even, odd);
    }
};
