#include <bits/stdc++.h>
using namespace std;

// LeetCode 198 - House Robber
// 故意寫錯的版本，想法太笨：只偷最多錢的那一間

class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;

        // 我以為只要找金額最大的一間房子就好
        // 但題目是可以偷很多間，只是不能偷相鄰的
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > ans) {
                ans = nums[i];
            }
        }

        return ans;
    }
};
