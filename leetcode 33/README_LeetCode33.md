# LeetCode 33 - Search in Rotated Sorted Array

## 題目重點

這題給一個原本由小到大排序，但後來被旋轉過的陣列 `nums`，以及一個目標值 `target`。

題目要求：

1. 如果 `target` 存在於陣列中，回傳它的 index。
2. 如果 `target` 不存在，回傳 `-1`。
3. 必須使用時間複雜度 `O(log n)` 的演算法。
4. 陣列中的數字不重複。

例如：

```txt
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

因為 `0` 出現在 index `4`。

再例如：

```txt
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

因為 `3` 不在陣列中。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 33 - Search in Rotated Sorted Array
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // 錯誤想法：直接用普通 binary search
        // 但陣列被旋轉過，不一定整體由小到大排序。
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};
```

---

## 錯誤原因

錯誤程式碼直接使用普通 binary search。

普通 binary search 的前提是整個陣列必須由小到大排序。  
但是這題的陣列被旋轉過，所以整體不一定是完全遞增的。

例如：

```txt
nums = [4,5,6,7,0,1,2], target = 0
```

這個陣列不是整體由小到大排序，因為：

```txt
7 後面接著 0
```

錯誤程式碼可能會看到中間值 `7`，因為 `7 > 0` 就往左半邊找。  
可是 `0` 其實在右半邊，所以會被錯過。

因此這題不能直接套普通 binary search，必須判斷哪一半是有排序的。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 33 - Search in Rotated Sorted Array
// Correct version

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // 左半邊是有排序的
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // 右半邊是有排序的
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
```

---

## 解題想法

這題仍然可以用 binary search，但每次要先判斷哪一半是有排序的。

因為陣列雖然被旋轉過，但切成左右兩半後，至少會有一半是正常排序的。

做法如下：

1. 設定 `left = 0`，`right = nums.size() - 1`。
2. 每次取中間位置 `mid`。
3. 如果 `nums[mid] == target`，直接回傳 `mid`。
4. 如果 `nums[left] <= nums[mid]`，代表左半邊是有排序的。
5. 判斷 `target` 是否落在左半邊的範圍內：
   - 如果是，就往左半邊找。
   - 如果不是，就往右半邊找。
6. 如果左半邊不是有排序的，代表右半邊一定是有排序的。
7. 判斷 `target` 是否落在右半邊的範圍內：
   - 如果是，就往右半邊找。
   - 如果不是，就往左半邊找。
8. 如果搜尋結束還沒找到，就回傳 `-1`。

---

## 心得

這題是 binary search 的變形題。

一開始如果直接使用普通 binary search，會因為陣列被旋轉過而判斷錯方向。  
正確做法是每次先找出哪一半是有排序的，再判斷 `target` 是否在那個範圍內。

這題讓我學到 binary search 不只適用於完全排序的陣列，也可以透過觀察局部有序的特性來解旋轉陣列問題。
