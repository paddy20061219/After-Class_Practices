# LeetCode 31 - Next Permutation

## 題目重點

這題給一個整數陣列 `nums`，要把它改成「下一個字典序排列」。

也就是在所有可能的排列中，找出剛好比目前排列大的下一個排列。

如果目前排列已經是最大的排列，就要把它改成最小排列。

例如：

```txt
Input: nums = [1,2,3]
Output: [1,3,2]
```

因為 `[1,3,2]` 是剛好比 `[1,2,3]` 大的下一個排列。

再例如：

```txt
Input: nums = [3,2,1]
Output: [1,2,3]
```

因為 `[3,2,1]` 已經是最大排列，所以要變回最小排列。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 31 - Next Permutation
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 錯誤想法：直接把整個陣列排序成由小到大
        // 但題目要求的是「下一個字典序排列」，不是最小排列。
        sort(nums.begin(), nums.end());
    }
};
```

---

## 錯誤原因

錯誤程式碼直接把整個陣列排序成由小到大。

但是題目要的是「下一個排列」，不是每次都變成最小排列。

例如：

```txt
Input: nums = [1,2,3]
Wrong Output: [1,2,3]
Correct Output: [1,3,2]
```

`[1,2,3]` 的下一個排列應該是 `[1,3,2]`，但是錯誤程式碼排序後還是 `[1,2,3]`。

再例如：

```txt
Input: nums = [1,3,2]
Wrong Output: [1,2,3]
Correct Output: [2,1,3]
```

所以不能直接排序整個陣列。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 31 - Next Permutation
// Correct version

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // 1. 從右往左找第一個 nums[i] < nums[i + 1] 的位置
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // 2. 如果有找到，從右邊找第一個比 nums[i] 大的數字並交換
        if (i >= 0) {
            int j = n - 1;

            while (nums[j] <= nums[i]) {
                j--;
            }

            swap(nums[i], nums[j]);
        }

        // 3. 把 i 後面的部分反轉，變成最小排列
        reverse(nums.begin() + i + 1, nums.end());
    }
};
```

---

## 解題想法

這題的核心是從右邊開始看，因為越右邊的數字改變，整個排列增加得越少。

做法如下：

1. 從右往左找第一個 `nums[i] < nums[i + 1]` 的位置。
2. 這個位置代表還有機會把排列變大。
3. 再從最右邊找第一個比 `nums[i]` 大的數字。
4. 把這兩個數字交換。
5. 交換後，`i` 後面的部分要反轉，讓後半段變成最小排列。
6. 如果找不到 `nums[i] < nums[i + 1]`，代表整個陣列是由大到小排列，已經是最大排列，直接反轉成最小排列。

例如：

```txt
nums = [1,3,2]
```

從右邊找：

```txt
1 < 3
```

所以 `1` 是要被換掉的位置。  
從右邊找比 `1` 大的數字，找到 `2`。  
交換後變成：

```txt
[2,3,1]
```

再把後面反轉：

```txt
[2,1,3]
```

所以答案是 `[2,1,3]`。

---

## 心得

這題不能用單純排序來解，因為題目要的是「剛好大一點」的排列。

一開始直接排序會忽略原本排列的順序，也不符合下一個字典序的定義。  
正確做法是從右邊找到可以變大的位置，交換後再把後面變成最小排列。

這題讓我學到字典序排列的規則，也練習到從右往左掃描、交換和反轉陣列的技巧。
