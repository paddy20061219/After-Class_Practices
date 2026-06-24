# LeetCode 198 - House Robber 訂正

## 題目重點

這題是小偷要偷一排房子，每間房子有不同金額。

限制是：

- 不能偷相鄰的兩間房子
- 可以偷多間房子
- 要讓偷到的總金額最大

所以這題不是單純找最大值，也不是每次看到大的就偷，  
因為要考慮「偷這間」會影響到旁邊的房子能不能偷。

這題很適合用 DP。

---

## 錯誤程式碼

```cpp
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
```

---

## 錯誤原因

這個錯誤寫法只找陣列裡面最大的數字。

可是題目不是說只能偷一間房子，  
而是可以偷很多間，只要不要偷相鄰的就好。

例如：

```text
nums = [2, 7, 9, 3, 1]
```

錯誤寫法會回傳：

```text
9
```

因為最大的一間是 9。

可是正確答案應該是：

```text
2 + 9 + 1 = 12
```

所以只偷最大的一間太笨了，會少算很多可以偷的房子。

---

## 正確程式碼

```cpp
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
```

---

## 解法想法

用 `dp[i]` 表示：

```text
偷到第 i 間房子為止，最多可以偷多少錢
```

每一間房子都有兩種選擇：

### 1. 不偷第 i 間

如果不偷第 `i` 間，那答案就跟前一間一樣：

```cpp
dp[i - 1]
```

### 2. 偷第 i 間

如果要偷第 `i` 間，那第 `i - 1` 間就不能偷，  
所以要加上 `dp[i - 2]`：

```cpp
dp[i - 2] + nums[i]
```

所以轉移式是：

```cpp
dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
```

最後答案是：

```cpp
dp[n - 1]
```

---

## 心得

這題一開始很容易想得太簡單，  
像是只找最大值，或是看到大的就偷。

但這樣會忽略「不能偷相鄰房子」這個限制。

我覺得這題的重點是要想到每一間房子只有兩個選擇：

- 偷
- 不偷

把這兩種情況比較之後，就可以慢慢推出答案。

這題算是 DP 的入門題，  
比背包簡單很多，但可以練到 `dp[i]` 的意思和轉移式。

---

## AI assistance note

這份訂正有使用 AI 幫忙整理錯誤原因和正確寫法。  
但我有自己理解 `dp[i]` 代表的意思，並把內容改成比較像自己上課筆記的寫法。
