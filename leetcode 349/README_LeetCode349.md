# LeetCode 349 - Intersection of Two Arrays

## 題目重點

這題給兩個整數陣列 `nums1` 和 `nums2`，要找出兩個陣列都有出現的元素。

題目要求：

1. 回傳兩個陣列的交集。
2. 答案中的每個元素只能出現一次。
3. 輸出順序不重要。

例如：

```txt
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
```

因為兩個陣列都有出現的數字是 `2`，而且答案不能重複。

再例如：

```txt
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
```

或：

```txt
Output: [4,9]
```

因為輸出順序不重要。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 349 - Intersection of Two Arrays
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        // 錯誤想法：只要兩個陣列中有相同數字就直接加入答案
        // 但題目要求答案不能有重複元素。
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    ans.push_back(nums1[i]);
                }
            }
        }

        return ans;
    }
};
```

---

## 錯誤原因

錯誤程式碼用雙層迴圈比較 `nums1` 和 `nums2`，只要發現相同數字就加入答案。

但是題目要求答案中的元素不能重複。

例如：

```txt
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Wrong Output: [2,2,2,2]
Correct Output: [2]
```

因為 `nums1` 裡有兩個 `2`，`nums2` 裡也有兩個 `2`，雙層迴圈會重複加入很多次。

所以這題不能只判斷兩個數字是否相同，還要避免答案中出現重複元素。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// LeetCode 349 - Intersection of Two Arrays
// Correct version

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> resultSet;

        // 先把 nums1 的元素放進 set
        for (int num : nums1) {
            set1.insert(num);
        }

        // 檢查 nums2 的元素是否也出現在 nums1
        for (int num : nums2) {
            if (set1.count(num)) {
                resultSet.insert(num);
            }
        }

        vector<int> ans;
        for (int num : resultSet) {
            ans.push_back(num);
        }

        return ans;
    }
};
```

---

## 解題想法

這題可以用 `unordered_set` 解。

`set` 的特性是：

```txt
同一個元素只會保存一次
```

所以很適合用來處理「不能重複」的問題。

做法如下：

1. 建立 `set1`，把 `nums1` 的所有元素放進去。
2. 建立 `resultSet`，用來存放答案。
3. 逐一檢查 `nums2` 的元素。
4. 如果某個數字也存在於 `set1`，代表它是交集元素。
5. 把這個數字加入 `resultSet`。
6. 最後把 `resultSet` 轉成 `vector<int>` 回傳。

因為 `resultSet` 不會存重複元素，所以答案自然不會重複。

---

## 心得

這題的重點不是單純找相同數字，而是要找「不重複的交集」。

如果直接用雙層迴圈，雖然可以找出相同元素，但很容易產生重複答案。  
使用 `unordered_set` 可以同時解決查找和去除重複的問題。

這題讓我學到，當題目要求元素不能重複時，可以優先考慮使用 `set` 或 `unordered_set`。
