# LeetCode 8 - String to Integer (atoi)

## 題目重點

這題要模擬 C 語言中的 `atoi` 函式，把字串轉成整數。

處理規則如下：

1. 先忽略字串前面的空白。
2. 判斷是否有正負號 `+` 或 `-`。
3. 從第一個數字開始讀取，直到遇到非數字字元為止。
4. 如果結果超過 32-bit signed integer 範圍：
   - 大於 `INT_MAX`，回傳 `2147483647`
   - 小於 `INT_MIN`，回傳 `-2147483648`

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <string>
using namespace std;

// LeetCode 8 - String to Integer (atoi)
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;

        // 錯誤想法：看到數字就直接累加，完全不處理空白、正負號、溢位
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + (s[i] - '0');
            }
        }

        return ans;
    }
};
```

---

## 錯誤原因

錯誤程式碼只要看到數字就直接加進答案，所以會有很多問題。

例如：

```txt
Input: "   -42"
Wrong Output: 42
Correct Output: -42
```

它沒有處理負號，所以答案會錯。

再例如：

```txt
Input: "4193 with words"
Output: 4193
```

這個例子剛好可能會對，但是如果是：

```txt
Input: "words and 987"
Wrong Output: 987
Correct Output: 0
```

因為題目規定如果一開始不是有效數字格式，就應該回傳 `0`，不能把後面的數字抓出來。

另外，錯誤程式碼也沒有處理整數溢位，例如：

```txt
Input: "91283472332"
Correct Output: 2147483647
```

---

## 正確程式碼

```cpp
#include <iostream>
#include <string>
#include <climits>
using namespace std;

// LeetCode 8 - String to Integer (atoi)
// Correct version

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();

        // 1. 跳過前面的空白
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. 判斷正負號
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // 3. 讀取數字，並檢查是否超過 int 範圍
        long long ans = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');

            if (sign == 1 && ans > INT_MAX) {
                return INT_MAX;
            }

            if (sign == -1 && -ans < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return sign * ans;
    }
};
```

---

## 心得

這題看起來只是字串轉整數，但其實重點在細節處理。

一開始我以為只要把字串裡的數字抓出來就好，但後來發現題目有很多規則，例如前面空白可以忽略、正負號只能出現在數字前面、遇到非數字要停止，還有整數超出範圍時要回傳邊界值。

這題讓我學到寫程式不能只看範例，要把題目的每個條件都完整處理，尤其是字串題常常會有很多特殊情況。
