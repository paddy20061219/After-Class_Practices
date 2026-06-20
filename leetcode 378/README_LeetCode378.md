# LeetCode 378 - Kth Smallest Element in a Sorted Matrix

## 題目重點

這題給一個 `n x n` 的矩陣 `matrix`，每一列和每一行都已經由小到大排序。

題目要求找出矩陣中第 `k` 小的元素。

注意：

1. 矩陣的每一列都是遞增排序。
2. 矩陣的每一行也是遞增排序。
3. 要找的是整個矩陣中第 `k` 小的數字，不是某一列中的第 `k` 小。
4. 矩陣中可能會有重複數字，重複數字也要算次數。

例如：

```txt
Input:
matrix = [
  [1, 5, 9],
  [10, 11, 13],
  [12, 13, 15]
]
k = 8

Output: 13
```

因為把所有數字由小到大排列後是：

```txt
1, 5, 9, 10, 11, 12, 13, 13, 15
```

第 8 小的數字是 `13`。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 378 - Kth Smallest Element in a Sorted Matrix
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;

        // 錯誤想法：只把第一列拿出來排序
        // 但答案可能在其他列裡面。
        for (int j = 0; j < matrix[0].size(); j++) {
            nums.push_back(matrix[0][j]);
        }

        sort(nums.begin(), nums.end());

        return nums[k - 1];
    }
};
```

---

## 錯誤原因

錯誤程式碼只把矩陣的第一列拿出來排序，然後回傳第 `k` 個元素。

但是題目要找的是整個矩陣中的第 `k` 小，不是第一列中的第 `k` 小。

例如：

```txt
matrix = [
  [1, 5, 9],
  [10, 11, 13],
  [12, 13, 15]
]
k = 8
```

錯誤程式碼只會看第一列：

```txt
1, 5, 9
```

這樣根本沒有包含其他列的數字，因此無法找到整個矩陣的第 8 小。

所以這個做法一定會漏掉資料，也可能造成陣列越界錯誤。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 378 - Kth Smallest Element in a Sorted Matrix
// Correct version

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];

        // 對答案做二分搜尋
        while (left < right) {
            int mid = left + (right - left) / 2;

            int count = countLessEqual(matrix, mid);

            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

private:
    int countLessEqual(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int row = n - 1;
        int col = 0;
        int count = 0;

        // 從左下角開始數有多少數字 <= target
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }

        return count;
    }
};
```

---

## 解題想法

這題可以用「二分搜尋答案」來解。

因為矩陣的最小值一定在左上角：

```txt
matrix[0][0]
```

最大值一定在右下角：

```txt
matrix[n - 1][n - 1]
```

所以答案一定在這個範圍內。

做法如下：

1. 設定 `left = matrix[0][0]`。
2. 設定 `right = matrix[n - 1][n - 1]`。
3. 每次取中間值 `mid`。
4. 計算矩陣中有多少數字 `<= mid`。
5. 如果 `count < k`，代表第 `k` 小的數字比 `mid` 大，所以往右找。
6. 如果 `count >= k`，代表第 `k` 小的數字可能是 `mid` 或更小，所以往左找。
7. 最後 `left` 就是第 `k` 小的數字。

計算 `<= target` 的數量時，可以從左下角開始：

```txt
如果 matrix[row][col] <= target
代表這一欄從第 0 列到 row 列都 <= target
所以 count += row + 1，然後往右走

如果 matrix[row][col] > target
代表這個數字太大，要往上走
```

---

## 心得

這題不能只看某一列或某一行，因為第 `k` 小是整個矩陣一起比較的結果。

一開始可能會想到把所有數字放進陣列排序，這樣雖然可以解，但沒有利用矩陣已經排序好的特性。  
用二分搜尋答案可以更有效率，也能練習如何根據「小於等於某個值的數量」來縮小搜尋範圍。

這題讓我學到，排序矩陣題目常常可以搭配二分搜尋來處理。
