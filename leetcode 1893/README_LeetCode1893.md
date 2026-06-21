# LeetCode 1893 - Check if All the Integers in a Range Are Covered

## 題目重點

這題會給很多個範圍 `ranges`，每個範圍長這樣：

```txt
[start, end]
```

代表從 `start` 到 `end` 的整數都有被包含。

題目還會給：

```txt
left
right
```

要檢查從 `left` 到 `right` 之間的每一個整數，是不是都有被 `ranges` 裡面的某個範圍包到。

如果全部都有被包到，就回傳：

```txt
true
```

只要有一個數字沒被包到，就回傳：

```txt
false
```

例如：

```txt
ranges = [[1,2],[3,4],[5,6]]
left = 2
right = 5
```

要檢查：

```txt
2, 3, 4, 5
```

這些數字都有被包到，所以答案是：

```txt
true
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1893 - Check if All the Integers in a Range Are Covered
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        // 蠢錯誤：完全不檢查 ranges
        // 直接說全部都有被 covered，這很明顯會錯。
        return true;
    }
};
```

---

## 錯誤原因

這個錯誤版本很明顯就是亂回傳。

它完全沒有檢查：

```txt
left 到 right 的每個數字
```

到底有沒有被 `ranges` 包到。

例如：

```txt
ranges = [[1,2]]
left = 1
right = 3
```

要檢查的是：

```txt
1, 2, 3
```

其中 `3` 沒有被任何 range 包到，所以正確答案應該是：

```txt
false
```

可是錯誤程式碼一定回傳：

```txt
true
```

所以會錯。

這題不能直接猜答案，要真的一個一個檢查。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1893 - Check if All the Integers in a Range Are Covered
// AC version

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int num = left; num <= right; num++){
            bool found = false;

            // 檢查 num 有沒有被任何一個 range 包到
            for(int i = 0; i < ranges.size(); i++){
                int start = ranges[i][0];
                int end = ranges[i][1];

                if(start <= num && num <= end){
                    found = true;
                    break;
                }
            }

            // 只要有一個數字沒被包到，就回傳 false
            if(found == false){
                return false;
            }
        }

        return true;
    }
};
```

---

## 解題想法

這題先不要想太難。

因為題目要問：

```txt
left 到 right 的每個數字有沒有被 cover
```

所以我們就真的從 `left` 跑到 `right`。

例如：

```cpp
for(int num = left; num <= right; num++)
```

每次拿一個 `num` 出來檢查。

接著看這個 `num` 有沒有在任何一個 range 裡面。

如果某個 range 是：

```txt
[start, end]
```

那 `num` 在裡面的條件就是：

```cpp
start <= num && num <= end
```

如果有找到，就代表這個數字有被 cover。

如果跑完全部 `ranges` 都找不到，就代表這個數字沒被包到，直接回傳：

```cpp
false
```

如果從 `left` 到 `right` 全部都通過，最後就回傳：

```cpp
true
```

---

## 心得

這題其實可以用比較進階的方法，像是差分陣列。  

但我覺得一開始用最直覺的方法比較好懂：  
就是把 `left` 到 `right` 每個數字都拿出來檢查。

這樣比較不容易想錯，也比較看得出題目到底在問什麼。

這題重點是要記得，只要有一個數字沒被 covered，答案就是 `false`。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
