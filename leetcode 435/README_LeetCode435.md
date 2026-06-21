# LeetCode 435 - Non-overlapping Intervals

## 題目重點

這題會給很多個區間 `intervals`。

每個區間長這樣：

```txt
[start, end]
```

題目要問：

```txt
最少要刪掉幾個 interval，才能讓剩下的 interval 都不要重疊
```

例如：

```txt
intervals = [[1,2],[2,3],[3,4],[1,3]]
```

其中 `[1,3]` 會跟其他區間重疊。

只要刪掉 `[1,3]`，剩下：

```txt
[1,2], [2,3], [3,4]
```

就不重疊了。

所以答案是：

```txt
1
```

注意：

```txt
[1,2] 和 [2,3]
```

這種不算重疊，因為一個剛好在 2 結束，另一個從 2 開始。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 435 - Non-overlapping Intervals
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 蠢錯誤：直接說不用刪任何 interval
        // 但如果區間有重疊，就一定可能需要刪掉一些。
        return 0;
    }
};
```

---

## 錯誤原因

這個錯誤版本完全沒有檢查區間有沒有重疊。

它直接回傳：

```cpp
0
```

意思是不用刪任何 interval。

可是很多測資明明需要刪掉區間。

例如：

```txt
intervals = [[1,2],[1,2],[1,2]]
```

這三個區間全部重疊。

最多只能留下其中一個，所以要刪掉兩個。  
正確答案應該是：

```txt
2
```

但錯誤程式碼會回傳：

```txt
0
```

所以很明顯不對。

這題一定要真的判斷重疊，不能直接猜答案。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 435 - Non-overlapping Intervals
// AC version

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return 0;
        }

        // 依照結束時間由小到大排序
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });

        int removeCount = 0;
        int lastEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            // 如果目前區間的開始 < 前一個保留區間的結束，代表重疊
            if(start < lastEnd){
                removeCount++;
            } else {
                lastEnd = end;
            }
        }

        return removeCount;
    }
};
```

---

## 解題想法

這題可以用貪心法。

想法是：

```txt
如果要留下最多不重疊的 interval，
就應該優先留下結束時間比較早的 interval。
```

因為結束得越早，後面越有空間接其他 interval。

所以第一步先照結束時間排序：

```cpp
sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
    return a[1] < b[1];
});
```

接著用 `lastEnd` 記錄目前保留下來的最後一個區間的結束位置。

如果目前 interval 的開始是：

```cpp
start < lastEnd
```

代表它跟前面保留的 interval 重疊，所以這個 interval 要刪掉：

```cpp
removeCount++;
```

如果沒有重疊，也就是：

```cpp
start >= lastEnd
```

代表可以保留，然後更新：

```cpp
lastEnd = end;
```

最後 `removeCount` 就是最少要刪掉的 interval 數量。

---

## 心得

這題跟 LeetCode 56 Merge Intervals 有點像，都是 interval 題。

不過這題不是要把區間合併，而是要刪掉最少的區間，讓剩下的不要重疊。

我覺得這題最重要的是要理解為什麼照結束時間排序。  
因為結束越早，後面越容易放更多區間。

還有要注意重疊判斷：

```txt
start < lastEnd 才算重疊
start == lastEnd 不算重疊
```

這個地方如果寫錯，答案就會錯。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
