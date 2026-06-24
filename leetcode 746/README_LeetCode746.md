# LeetCode 746 - Min Cost Climbing Stairs 訂正

## 題目重點

這題是要算爬樓梯的最小花費。

每一格都有一個 `cost[i]`，踩到那一格就要付錢。  
每次可以爬 1 階或 2 階，而且可以從第 0 階或第 1 階開始。

最後目標是爬到最上面，也就是超過最後一格的位置。

我覺得這題重點是：

- 不一定每次都踩最便宜的那格
- 不能只看奇數格或偶數格
- 要記錄「走到某一階之前最少花多少錢」
- 所以比較適合用 DP

---

## 錯誤程式碼

```cpp
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
```

---

## 錯誤原因

我原本想說，既然一次可以走 2 階，那好像就可以只走偶數階或只走奇數階，  
所以把偶數位置的 cost 加起來，再把奇數位置的 cost 加起來，最後取比較小的。

可是這樣是錯的。

因為實際上走法不是只有：

```text
0 -> 2 -> 4 -> ...
1 -> 3 -> 5 -> ...
```

也可以像這樣混著走：

```text
1 -> 3 -> 4 -> 6
0 -> 1 -> 3 -> 5
```

所以只分奇數和偶數會漏掉很多可能的路線。

例如：

```text
cost = [10, 15, 20]
```

正確答案是 15，因為可以從第 1 階開始，直接走到頂端。  
但錯誤寫法會算：

```text
even = 10 + 20 = 30
odd = 15
```

這個例子剛好對，可是換成比較複雜的就可能錯。

例如：

```text
cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
```

這種就不能單純只算奇數或偶數。

---

## 正確程式碼

```cpp
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
```

---

## 解法想法

用 `dp[i]` 表示走到第 `i` 階的最小花費。

因為每次只能走 1 階或 2 階，所以要到第 `i` 階只有兩種可能：

1. 從第 `i - 1` 階走上來
2. 從第 `i - 2` 階走上來

所以轉移式是：

```cpp
dp[i] = min(dp[i - 1] + cost[i - 1],
            dp[i - 2] + cost[i - 2]);
```

這裡的意思是：

- 如果從 `i - 1` 走來，就要先花到 `i - 1` 的錢，再付 `cost[i - 1]`
- 如果從 `i - 2` 走來，就要先花到 `i - 2` 的錢，再付 `cost[i - 2]`

最後答案就是：

```cpp
dp[n]
```

因為 `n` 代表已經走到樓梯頂端了。

---

## 心得

這題一開始看起來很像可以用很簡單的貪心或奇偶數去做，  
但其實會漏掉很多走法。

後來才發現這題是很標準的 DP 題。  
只要想清楚 `dp[i]` 是「到第 i 階最少花費」，後面就比較好寫了。

我覺得這題可以拿來練 DP 的基本觀念，因為它不像背包那麼難，  
但是可以讓我理解為什麼有時候不能只看眼前便宜的選擇。

---

## AI assistance note

這份訂正有使用 AI 幫忙整理錯誤原因和正確解法，  
但我有自己理解題目的 DP 轉移式，並把內容改成比較像自己的筆記。
