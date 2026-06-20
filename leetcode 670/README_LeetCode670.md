# LeetCode 670 - Maximum Swap

## 題目重點

這題給一個非負整數 `num`，最多只能交換其中兩個數字一次，要求交換後得到最大的數字。

例如：

```txt
Input: num = 2736
Output: 7236
```

因為可以交換 `2` 和 `7`，得到最大的數字 `7236`。

再例如：

```txt
Input: num = 9973
Output: 9973
```

因為原本已經是最大排列，不需要交換。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// LeetCode 670 - Maximum Swap
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);

        // 錯誤想法：直接把所有數字由大到小排序
        // 但題目只允許交換一次，不能任意重排全部數字。
        sort(s.begin(), s.end(), greater<char>());

        return stoi(s);
    }
};
```

---

## 錯誤原因

錯誤程式碼直接把所有數字排序成由大到小。

但是題目規定是：

```txt
最多只能交換一次
```

不是可以任意重排整個數字。

例如：

```txt
Input: num = 98368
```

錯誤程式碼會把所有數字排序成：

```txt
98863
```

但是這需要重新排列多個位置，不是一次交換可以完成的結果。

正確答案是：

```txt
98863
```

這個例子剛好一次交換也能達成，但不是因為排序方法正確。

再看另一個例子：

```txt
Input: num = 1993
Wrong Output: 9931
Correct Output: 9913
```

`1993` 最多只能交換一次，所以只能把第一個 `1` 和最後一個 `9` 交換，得到：

```txt
9913
```

不能把所有數字重新排序成 `9931`。

---

## 正確程式碼

```cpp
#include <iostream>
#include <string>
using namespace std;

// LeetCode 670 - Maximum Swap
// Correct version

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int last[10];

        // 紀錄每個數字最後一次出現的位置
        for (int i = 0; i < 10; i++) {
            last[i] = -1;
        }

        for (int i = 0; i < s.length(); i++) {
            last[s[i] - '0'] = i;
        }

        // 從左到右找，看能不能用右邊更大的數字來交換
        for (int i = 0; i < s.length(); i++) {
            int currentDigit = s[i] - '0';

            for (int d = 9; d > currentDigit; d--) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return stoi(s);
                }
            }
        }

        return num;
    }
};
```

---

## 解題想法

這題可以把整數轉成字串來處理，因為交換數字的位置用字串比較方便。

核心想法是：  
要讓數字最大，就要從越左邊的位置開始改善，因為左邊位數影響最大。

做法如下：

1. 先把 `num` 轉成字串 `s`。
2. 用陣列 `last[10]` 紀錄每個數字最後一次出現的位置。
3. 從左到右掃描每個位置。
4. 對目前數字 `s[i]`，從 `9` 往下找有沒有比它更大的數字。
5. 如果某個更大的數字出現在右邊，就立刻交換。
6. 交換一次後直接回傳答案。
7. 如果完全沒有可以交換的地方，代表原本已經最大，回傳原本的 `num`。

---

## 心得

這題的重點是題目只允許交換一次，所以不能直接把數字全部排序。

一開始容易以為把數字排成最大就好，但這樣會違反題目限制。  
正確做法是從左邊開始找第一個可以變大的位置，並且要盡量換成右邊最大的數字。

這題讓我學到，在貪心題中要注意限制條件。  
不是只要得到最大結果就好，還要確保操作次數符合題目規定。
