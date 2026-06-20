# LeetCode 35 - Search Insert Position

## 題目重點

這題給一個已經由小到大排序好的整數陣列 `nums`，以及一個目標值 `target`。

題目要求：

1. 如果 `target` 已經存在於陣列中，回傳它的 index。
2. 如果 `target` 不存在，回傳它應該被插入的位置。
3. 插入後仍然要保持陣列由小到大排序。
4. 題目要求時間複雜度是 `O(log n)`，所以適合使用 binary search。

例如：

```txt
Input: nums = [1,3,5,6], target = 5
Output: 2
```

因為 `5` 已經存在於 index `2`。

再例如：

```txt
Input: nums = [1,3,5,6], target = 2
Output: 1
```

因為 `2` 應該插入在 `1` 和 `3` 中間，也就是 index `1`。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 35 - Search Insert Position
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 錯誤想法：只找 target 有沒有出現
        // 如果沒找到就回傳 -1，但題目要求回傳應該插入的位置。
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }

        return -1;
    }
};
```

---

## 錯誤原因

錯誤程式碼只處理 `target` 已經存在的情況。

但是題目要求如果 `target` 不存在，也要回傳它應該插入的位置，而不是回傳 `-1`。

例如：

```txt
Input: nums = [1,3,5,6], target = 2
Wrong Output: -1
Correct Output: 1
```

因為 `2` 雖然不在陣列中，但如果要保持排序，應該插入在 index `1`。

再例如：

```txt
Input: nums = [1,3,5,6], target = 7
Wrong Output: -1
Correct Output: 4
```

因為 `7` 比所有數字都大，所以應該插入在陣列最後面，也就是 index `4`。

所以這題不能只判斷有沒有找到，還要找出插入位置。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 35 - Search Insert Position
// Correct version

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        // 找第一個 >= target 的位置
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};
```

---

## 解題想法

這題可以用 binary search 找出第一個大於或等於 `target` 的位置。

這個位置有兩種可能：

1. 如果 `nums[index] == target`，代表這就是 `target` 的位置。
2. 如果 `target` 不存在，這個 index 就是它應該插入的位置。

做法如下：

1. 設定 `left = 0`。
2. 設定 `right = nums.size()`，因為答案可能是陣列最後一格後面的位置。
3. 每次取中間位置 `mid`。
4. 如果 `nums[mid] < target`，代表插入位置一定在右邊，所以 `left = mid + 1`。
5. 否則代表 `mid` 可能就是答案，所以 `right = mid`。
6. 最後 `left` 就是答案。

例如：

```txt
nums = [1,3,5,6], target = 2
```

第一個大於或等於 `2` 的數字是 `3`，它的位置是 index `1`，所以答案是 `1`。

---

## 心得

這題是 binary search 的基本應用，但重點不是只找目標值，而是要找插入位置。

如果只用一般搜尋，找不到就回傳 `-1`，就會忽略題目的要求。  
正確做法是找第一個大於或等於 `target` 的位置，也就是 lower bound 的概念。

這題讓我學到 binary search 不只可以找某個值，也可以用來找邊界位置。
