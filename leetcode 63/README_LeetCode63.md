# LeetCode 63 - Unique Paths II

## 題目重點

這題跟 LeetCode 62 很像，都是從左上角走到右下角。

機器人一樣只能走：

```txt
往右
往下
```

但是這題多了障礙物。

`obstacleGrid[i][j]` 的意思是：

```txt
0 = 可以走
1 = 有障礙物，不能走
```

題目要算有幾種路徑可以從左上角走到右下角，而且不能踩到障礙物。

例如：

```txt
obstacleGrid = [
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
```

中間那格是障礙物，所以不能走。  
答案是：

```txt
2
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 63 - Unique Paths II
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // 蠢錯誤：完全不管障礙物
        // 直接回傳 m + n，這跟路徑數量其實沒關係。
        return m + n;
    }
};
```

---

## 錯誤原因

這個錯誤版本很明顯就是亂算。

它只拿：

```cpp
m + n
```

當答案，可是路徑數量不是用列數加欄數算的。

更大的問題是它完全沒有看障礙物。

例如：

```txt
obstacleGrid = [
  [0,1],
  [0,0]
]
```

這時候右邊那格不能走，但是錯誤程式碼根本不管，還是直接回傳：

```txt
2 + 2 = 4
```

這一定不對。

這題要考慮每一格能不能走，不能只看矩陣大小。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 63 - Unique Paths II
// AC version

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 起點如果有障礙物，根本不能出發
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        dp[0][0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0) {
                        dp[i][j] += dp[i - 1][j];
                    }

                    if (j > 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
```

---

## 解題想法

這題可以用 DP。

先想一件事：

```txt
走到某一格的方法數 = 從上面來的方法數 + 從左邊來的方法數
```

所以可以設：

```txt
dp[i][j] = 走到第 i 列第 j 欄的方法數
```

但是如果這一格是障礙物：

```txt
obstacleGrid[i][j] == 1
```

那這一格不能走，所以：

```txt
dp[i][j] = 0
```

如果不是障礙物，就把上面和左邊的方法數加起來。

```cpp
if (i > 0) dp[i][j] += dp[i - 1][j];
if (j > 0) dp[i][j] += dp[i][j - 1];
```

起點也要特別注意。  
如果起點本身就是障礙物，那機器人一開始就不能走，所以答案直接是 `0`。

最後答案就是：

```cpp
dp[m - 1][n - 1]
```

---

## 心得

這題其實就是 LeetCode 62 加上障礙物。

原本沒有障礙物時，每格可以從上面和左邊加過來。  
但現在如果某一格是 `1`，那格就不能走，方法數要變成 0。

我覺得這題比較容易忘記的是起點有障礙物的情況。  
如果一開始就不能站，那後面也不用算了。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
