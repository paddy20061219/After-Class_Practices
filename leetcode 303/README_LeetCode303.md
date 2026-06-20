# LeetCode 303 - Range Sum Query - Immutable

## 題目重點

這題會先給一個整數陣列 `nums`，然後要多次查詢某一段範圍的總和。

查詢格式是：

```txt
sumRange(left, right)
```

意思是要回傳：

```txt
nums[left] + nums[left + 1] + ... + nums[right]
```

注意 `left` 和 `right` 兩邊都要包含。

例如：

```txt
nums = [-2, 0, 3, -5, 2, -1]
```

如果查詢：

```txt
sumRange(0, 2)
```

答案是：

```txt
-2 + 0 + 3 = 1
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 303 - Range Sum Query - Immutable
// Wrong version: this code is intentionally incorrect.

class NumArray {
private:
    vector<int> nums;

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }

    int sumRange(int left, int right) {
        int sum = 0;

        // 錯誤想法：只算到 right 前一個位置
        // 但題目要求 left 到 right 都要包含。
        for (int i = left; i < right; i++) {
            sum += nums[i];
        }

        return sum;
    }
};
```

---

## 錯誤原因

錯誤程式碼的迴圈條件寫成：

```cpp
i < right
```

這樣會少算 `nums[right]`。

但是題目要求 `left` 到 `right` 都要包含，所以應該要算到右邊界。

例如：

```txt
nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2)
```

錯誤程式碼只會算：

```txt
nums[0] + nums[1] = -2 + 0 = -2
```

但正確應該是：

```txt
nums[0] + nums[1] + nums[2] = -2 + 0 + 3 = 1
```

所以這個錯誤主要是右邊界沒有包含進去。

另外，如果每次查詢都用迴圈重新加總，雖然有些測資可以過，但查詢很多次時效率比較差。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 303 - Range Sum Query - Immutable
// Correct version

class NumArray {
private:
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);

        // prefix[i + 1] 代表 nums[0] 到 nums[i] 的總和
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        // nums[left] 到 nums[right] 的總和
        return prefix[right + 1] - prefix[left];
    }
};
```

---

## 解題想法

這題適合用前綴和。

因為 `sumRange` 可能會被呼叫很多次，如果每次都從 `left` 加到 `right`，會比較慢。

所以可以先在建構子裡把前綴和算好。

我用：

```cpp
prefix[i + 1] = prefix[i] + nums[i];
```

這樣 `prefix[0]` 是 `0`，比較方便處理範圍。

如果要算：

```txt
nums[left] 到 nums[right]
```

就可以直接用：

```cpp
prefix[right + 1] - prefix[left]
```

不用每次重新跑迴圈。

---

## 心得

這題讓我比較清楚前綴和的用途。

如果只有查一次總和，直接用迴圈也可以。可是這題會重複查詢很多次，所以先把累積總和存起來會比較好。

這題也提醒我邊界要看清楚，`right` 是有包含的。如果迴圈少寫一個等號，就會少算最後一個數字。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
