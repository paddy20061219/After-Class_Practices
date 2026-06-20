# LeetCode 121 - Best Time to Buy and Sell Stock

## 題目重點

這題給一個陣列 `prices`，其中 `prices[i]` 代表第 `i` 天的股票價格。

你只能做一次買賣：

1. 選一天買入股票。
2. 選未來某一天賣出股票。
3. 買入日期一定要在賣出日期之前。
4. 回傳可以得到的最大利潤。
5. 如果無法賺錢，就回傳 `0`。

例如：

```txt
Input: prices = [7,1,5,3,6,4]
Output: 5
```

因為可以在價格 `1` 的時候買入，在價格 `6` 的時候賣出，利潤是：

```txt
6 - 1 = 5
```

---

## 錯誤程式碼

```cpp
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
```

---

## 錯誤原因

錯誤程式碼只找整個陣列中的最低價和最高價，然後直接相減。

但是題目規定一定要先買再賣，也就是買入日期必須在賣出日期之前。

例如：

```txt
Input: prices = [7,6,4,3,1]
Wrong Output: 6
Correct Output: 0
```

錯誤程式碼會用最高價 `7` 減最低價 `1`，得到 `6`。  
可是 `7` 出現在第 1 天，`1` 出現在最後一天，不能先賣再買。

所以這題不能只看最大值和最小值，還要注意時間順序。

---

## 正確程式碼

```cpp
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
```

---

## 解題想法

這題可以用一次迴圈解決。

核心想法是：

```txt
每一天都假設今天是賣出日
```

那麼今天能得到的最大利潤，就是：

```txt
今天價格 - 之前出現過的最低價格
```

做法如下：

1. 用 `minPrice` 記錄目前看過的最低價格。
2. 用 `bestProfit` 記錄目前最大利潤。
3. 從左到右掃描價格。
4. 每一天先計算如果今天賣出可以賺多少。
5. 更新最大利潤。
6. 再更新目前最低買入價格。
7. 最後回傳 `bestProfit`。

---

## 心得

這題看起來像是找最大值和最小值，但其實重點是順序。

股票一定要先買後賣，所以不能直接拿整個陣列的最大值減最小值。  
正確做法是從左到右掃描，邊走邊記錄目前以前看過的最低買入價格。

這題讓我學到，陣列題目不只要看數值大小，也要注意元素出現的先後順序。
