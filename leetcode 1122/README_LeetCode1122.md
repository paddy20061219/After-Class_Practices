# LeetCode 1122 - Relative Sort Array

## 題目重點

這題給兩個陣列 `arr1` 和 `arr2`。

題目要求重新排列 `arr1`，規則如下：

1. `arr2` 中的元素順序代表優先排序順序。
2. 如果 `arr1` 的元素有出現在 `arr2`，就要按照 `arr2` 的順序排列。
3. 沒有出現在 `arr2` 的元素，要放在最後。
4. 放在最後的元素要由小到大排序。

例如：

```txt
Input:
arr1 = [2,3,1,3,2,4,6,7,9,2,19]
arr2 = [2,1,4,3,9,6]

Output:
[2,2,2,1,4,3,3,9,6,7,19]
```

因為 `arr2` 的順序是：

```txt
2, 1, 4, 3, 9, 6
```

所以 `arr1` 裡有出現這些數字時，要按照這個順序放。  
剩下的 `7` 和 `19` 沒有出現在 `arr2`，所以放最後並由小到大排列。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 1122 - Relative Sort Array
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // 錯誤想法：直接把 arr1 由小到大排序
        // 但題目要求要依照 arr2 的相對順序排列。
        sort(arr1.begin(), arr1.end());

        return arr1;
    }
};
```

---

## 錯誤原因

錯誤程式碼直接把 `arr1` 由小到大排序。

但是題目不是要普通排序，而是要按照 `arr2` 給的相對順序排序。

例如：

```txt
arr1 = [2,3,1,3,2,4,6,7,9,2,19]
arr2 = [2,1,4,3,9,6]
```

錯誤程式碼會輸出：

```txt
[1,2,2,2,3,3,4,6,7,9,19]
```

但是正確答案應該是：

```txt
[2,2,2,1,4,3,3,9,6,7,19]
```

因為 `2` 在 `arr2` 中排第一，所以所有 `2` 都要先放。  
`1` 在 `arr2` 中排第二，所以接著放 `1`。  
不能只用數字大小排序。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// LeetCode 1122 - Relative Sort Array
// Correct version

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> count;

        // 統計 arr1 中每個數字出現幾次
        for (int num : arr1) {
            count[num]++;
        }

        vector<int> ans;

        // 先依照 arr2 的順序放入答案
        for (int num : arr2) {
            while (count[num] > 0) {
                ans.push_back(num);
                count[num]--;
            }
        }

        vector<int> rest;

        // 把沒有出現在 arr2 的數字收集起來
        for (auto item : count) {
            int num = item.first;
            int times = item.second;

            while (times > 0) {
                rest.push_back(num);
                times--;
            }
        }

        // 剩下的數字要由小到大排序
        sort(rest.begin(), rest.end());

        for (int num : rest) {
            ans.push_back(num);
        }

        return ans;
    }
};
```

---

## 解題想法

這題可以用計數的方式解。

因為要按照 `arr2` 的順序排列，所以不能直接對 `arr1` 排序。

做法如下：

1. 先統計 `arr1` 中每個數字出現幾次。
2. 依照 `arr2` 的順序，把對應數字放進答案。
3. 每放一次，就把該數字的次數減一。
4. `arr2` 處理完後，剩下的數字代表沒有出現在 `arr2`。
5. 把剩下的數字收集起來並由小到大排序。
6. 最後接在答案後面。

這樣就能同時符合：

```txt
arr2 中的數字照 arr2 順序
不在 arr2 中的數字放最後並排序
```

---

## 心得

這題容易錯在把它當成普通排序題。

其實這題是「相對排序」，排序規則不是數字大小，而是 `arr2` 給定的順序。  
只有不在 `arr2` 裡面的數字，才需要照一般大小排序。

這題讓我學到，排序題不一定都是用內建排序就能解，有時候要根據題目給的特殊規則來設計排序方式。
