#include <iostream>
#include <vector>
using namespace std;

// LeetCode 121 - Best Time to Buy and Sell Stock
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;

        // 錯誤想法：只找最大價格和最小價格相減
        // 但沒有確認買入日期一定要在賣出日期之前。
        int minPrice = prices[0];
        int maxPrice = prices[0];

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            }

            if (price > maxPrice) {
                maxPrice = price;
            }
        }

        maxProfit = maxPrice - minPrice;
        return maxProfit;
    }
};
