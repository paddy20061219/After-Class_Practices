# LeetCode 703 - Kth Largest Element in a Stream

## 題目重點

這題要設計一個 `KthLargest` 類別。

一開始會給：

```txt
k
nums
```

之後每次呼叫：

```cpp
add(val)
```

就代表有一個新的數字加入資料流。

每次加入新數字後，要回傳目前所有數字中的第 `k` 大。

例如：

```txt
k = 3
nums = [4,5,8,2]
```

這時候第 3 大是 `4`。

接著：

```txt
add(3)  -> 4
add(5)  -> 5
add(10) -> 5
add(9)  -> 8
add(4)  -> 8
```

因為每次加入後，都要重新看目前所有數字的第 3 大是多少。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 703 - Kth Largest Element in a Stream
// wrong version: this code is intentionally very wrong.

class KthLargest {
private:
    int kValue;
    vector<int> nums;

public:
    KthLargest(int k, vector<int>& nums) {
        kValue = k;
        this->nums = nums;
    }

    int add(int val) {
        nums.push_back(val);

        // 蠢錯誤：直接回傳最新加入的數字
        // 題目要的是目前第 k 大，不是剛加入的 val。
        return val;
    }
};
```

---

## 錯誤原因

這個錯誤版本每次 `add(val)` 都直接回傳 `val`。

可是題目要的是：

```txt
目前所有數字中的第 k 大
```

不是最新加入的數字。

例如：

```txt
k = 3
nums = [4,5,8,2]
add(3)
```

加入 `3` 後，所有數字是：

```txt
[4,5,8,2,3]
```

由大到小大概是：

```txt
8,5,4,3,2
```

第 3 大是：

```txt
4
```

但是錯誤程式碼會直接回傳：

```txt
3
```

所以明顯錯了。

這題一定要一直維護目前第 `k` 大的數字，不能只看最新加入的值。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

// LeetCode 703 - Kth Largest Element in a Stream
// AC version

class KthLargest {
private:
    int kValue;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        kValue = k;

        for(int num : nums){
            minHeap.push(num);

            if(minHeap.size() > kValue){
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);

        if(minHeap.size() > kValue){
            minHeap.pop();
        }

        return minHeap.top();
    }
};
```

---

## 解題想法

這題可以用 min heap。

我們只保留目前最大的 `k` 個數字。  
如果 heap 裡面一直維持 `k` 個數字，那 heap 最上面那個最小值，就是第 `k` 大。

例如目前最大的 3 個數字是：

```txt
8, 5, 4
```

其中最小的是：

```txt
4
```

所以第 3 大就是 `4`。

在 C++ 裡可以這樣建立 min heap：

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
```

做法：

1. 把數字放進 `minHeap`。
2. 如果 `minHeap.size() > k`，就把最小的丟掉。
3. 這樣 heap 裡永遠只留下最大的 `k` 個數字。
4. `minHeap.top()` 就是這 `k` 個數字中最小的，也就是整體第 `k` 大。

`add(val)` 也是一樣：

```cpp
minHeap.push(val);
if(minHeap.size() > kValue){
    minHeap.pop();
}
return minHeap.top();
```

---

## 心得

這題如果每次 `add()` 都把全部數字排序，也可以想得通，但是會比較麻煩。

用 heap 的想法比較好：  
不用保留所有排序，只要保留最大的 `k` 個數字就好。

我覺得這題要先搞懂一句話：

```txt
最大的 k 個數字裡面，最小的那個就是第 k 大
```

理解這句後，min heap 就比較好懂了。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
