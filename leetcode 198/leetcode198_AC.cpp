#include <bits/stdc++.h>
using namespace std;

// LeetCode 198 - House Robber
// AC 版本，基本 DP 寫法

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);

        // dp[i] 代表偷到第 i 間為止，最多可以偷多少錢
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            // 第 i 間有兩種選擇：
            // 1. 不偷第 i 間，所以答案跟 dp[i-1] 一樣
            // 2. 偷第 i 間，所以要加 dp[i-2]
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};
