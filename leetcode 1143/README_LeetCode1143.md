# LeetCode 1143 - Longest Common Subsequence

## 題目重點

這題要找兩個字串的 longest common subsequence，也就是最長共同子序列。

Subsequence 的意思是：

```txt
可以刪掉一些字元，但不能改變原本字元的順序
```

例如：

```txt
text1 = "abcde"
text2 = "ace"
```

`"ace"` 是 `"abcde"` 的 subsequence，因為它保持原本順序：

```txt
a -> c -> e
```

所以這題答案是：

```txt
3
```

因為最長共同子序列是 `"ace"`。

注意 subsequence 不是 substring。  
substring 要連在一起，但 subsequence 可以中間跳過字元。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <string>
using namespace std;

// LeetCode 1143 - Longest Common Subsequence
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int count = 0;

        // 蠢錯誤：只比較同一個 index 的字元
        // 但 subsequence 可以跳過字元，不一定要在同一個位置。
        int n = min(text1.length(), text2.length());

        for(int i = 0; i < n; i++){
            if(text1[i] == text2[i]){
                count++;
            }
        }

        return count;
    }
};
```

---

## 錯誤原因

這個錯誤版本只比較兩個字串同一個位置的字元。

可是 subsequence 不需要在同一個 index，只要順序一樣就可以。

例如：

```txt
text1 = "abcde"
text2 = "ace"
```

正確答案是：

```txt
3
```

因為共同子序列是：

```txt
a c e
```

但是錯誤程式碼會比較：

```txt
text1[0] = a, text2[0] = a  相同
text1[1] = b, text2[1] = c  不同
text1[2] = c, text2[2] = e  不同
```

所以它只會回傳：

```txt
1
```

這明顯錯了。

這題不能只看同一個位置，因為字元可以跳過，但是順序不能亂。

---

## 正確程式碼

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 1143 - Longest Common Subsequence
// AC version

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){

                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }

            }
        }

        return dp[m][n];
    }
};
```

---

## 解題想法

這題可以用 DP。

設：

```txt
dp[i][j] = text1 前 i 個字元 和 text2 前 j 個字元 的 LCS 長度
```

因為 `dp` 多開一格，所以字串位置要用：

```cpp
text1[i - 1]
text2[j - 1]
```

如果這兩個字元一樣：

```cpp
text1[i - 1] == text2[j - 1]
```

代表這個字元可以一起放進共同子序列，所以：

```cpp
dp[i][j] = dp[i - 1][j - 1] + 1;
```

如果這兩個字元不一樣，就代表不能同時用這兩個字元。  
這時候要看：

```txt
不要 text1 目前這個字元
或
不要 text2 目前這個字元
```

哪一個比較好：

```cpp
dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
```

最後答案就是：

```cpp
dp[m][n]
```

---

## 心得

這題一開始會覺得字串比對很麻煩。

我覺得要先分清楚 subsequence 和 substring。  
這題是 subsequence，所以中間可以跳過字元，只要順序不變就好。

如果只比較同一個 index，會漏掉很多情況。  
用 DP 可以把「目前兩個字元要不要用」這件事慢慢算出來。

這題對我來說比較難的地方是 `i - 1` 和 `j - 1`，因為 dp 陣列多開一格，字串 index 會差一格，要小心。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
