#include <bits/stdc++.h>
using namespace std;

// LeetCode 746 - Min Cost Climbing Stairs
// AC 版本

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n + 1, 0);

        // dp[i] 代表到第 i 階最少要花多少錢
        // 可以從 i-1 走上來，也可以從 i-2 走上來
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1],
                        dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    }
};
