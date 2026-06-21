# LeetCode 347 - Top K Frequent Elements

## 題目重點

這題給一個整數陣列 `nums`，還有一個整數 `k`。

題目要找出：

```txt
出現次數最多的 k 個數字
```

回傳順序不重要。

例如：

```txt
nums = [1,1,1,2,2,3]
k = 2
```

每個數字出現次數是：

```txt
1 出現 3 次
2 出現 2 次
3 出現 1 次
```

所以出現最多的 2 個數字是：

```txt
[1,2]
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 347 - Top K Frequent Elements
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        // 蠢錯誤：直接回傳前 k 個數字
        // 題目要的是出現次數最高的 k 個數字，不是陣列前 k 個。
        for(int i = 0; i < k && i < nums.size(); i++){
            ans.push_back(nums[i]);
        }

        return ans;
    }
};
```

---

## 錯誤原因

這個錯誤版本只是把陣列前 `k` 個數字拿出來。

可是題目要的是：

```txt
出現次數最多的 k 個數字
```

不是：

```txt
位置最前面的 k 個數字
```

例如：

```txt
nums = [1,1,1,2,2,3]
k = 2
```

錯誤程式碼會回傳：

```txt
[1,1]
```

但這不對，因為答案不能只是照原本位置拿。  
正確應該是：

```txt
[1,2]
```

因為 `1` 和 `2` 是出現次數最多的兩個不同數字。

所以這題一定要先統計每個數字出現幾次。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// LeetCode 347 - Top K Frequent Elements
// AC version

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        // 先統計每個數字出現幾次
        for(int num : nums){
            count[num]++;
        }

        priority_queue<pair<int, int>> pq;

        // pair 的 first 放次數，second 放數字
        for(auto item : count){
            int num = item.first;
            int times = item.second;

            pq.push({times, num});
        }

        vector<int> ans;

        // 拿出出現次數最多的 k 個數字
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
```

---

## 解題想法

這題可以分成兩步。

第一步：先算每個數字出現幾次。

可以用：

```cpp
unordered_map<int, int> count;
```

例如看到一個數字 `num`，就做：

```cpp
count[num]++;
```

這樣就可以知道每個數字的出現次數。

第二步：找出次數最多的 `k` 個。

我用 `priority_queue`，也就是 heap。  
C++ 的 `priority_queue` 預設會把最大的東西放在最上面。

我放進去的是：

```cpp
{times, num}
```

意思是：

```txt
times = 出現次數
num = 原本的數字
```

這樣出現次數越多的數字，就會越前面被拿出來。

最後拿 `k` 次：

```cpp
pq.top().second
```

就是答案中的數字。

---

## 心得

這題不能只看陣列順序，也不能只看數字大小。

真正重要的是「出現次數」。  
所以第一步一定要先統計每個數字出現幾次。

我覺得這題可以練到兩個東西：

```txt
unordered_map 用來計數
priority_queue 用來拿最大值
```

對我來說比較要記的是，`pair` 裡面我把次數放前面，數字放後面，這樣 heap 才會優先按照次數排序。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
