#include <iostream>
#include <vector>
using namespace std;

// LeetCode 121 - Best Time to Buy and Sell Stock
// Correct version

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int bestProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            // 今天賣出的利潤
            int profit = prices[i] - minPrice;

            if (profit > bestProfit) {
                bestProfit = profit;
            }

            // 更新目前看過的最低買入價格
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
        }

        return bestProfit;
    }
};
