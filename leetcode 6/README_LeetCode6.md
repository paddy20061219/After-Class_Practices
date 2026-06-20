# LeetCode 6 - Zigzag Conversion

## 題目重點

這題要把字串按照 Zigzag 形狀排列，再依照每一列由左到右讀出結果。

例如：

```txt
Input: s = "PAYPALISHIRING", numRows = 3
```

排列方式會像這樣：

```txt
P   A   H   N
A P L S I I G
Y   I   R
```

所以輸出是：

```txt
PAHNAPLSIIGYIR
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <string>
using namespace std;

// LeetCode 6 - Zigzag Conversion
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";

        // 錯誤想法：直接把每 numRows 個字元分成一組，
        // 但這完全沒有處理 Zigzag 的斜線部分。
        for (int row = 0; row < numRows; row++) {
            for (int i = row; i < s.length(); i += numRows) {
                ans += s[i];
            }
        }

        return ans;
    }
};
```

---

## 錯誤原因

錯誤程式碼把字串當成普通直向排列來處理，每次固定跳 `numRows` 個位置。

但是 Zigzag 不是單純直上直下，它的排列方式會先往下走，再往上斜著走。

例如：

```txt
s = "PAYPALISHIRING", numRows = 3
```

錯誤程式碼會把它想成：

```txt
P P I I
A A S R G
Y L H N
```

這不是題目要求的 Zigzag 排列。

真正的排列應該是：

```txt
P   A   H   N
A P L S I I G
Y   I   R
```

所以不能只用固定間隔去取字元。

---

## 正確程式碼

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// LeetCode 6 - Zigzag Conversion
// Correct version

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);
        int currentRow = 0;
        int direction = 1;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0) {
                direction = 1;
            } else if (currentRow == numRows - 1) {
                direction = -1;
            }

            currentRow += direction;
        }

        string ans = "";
        for (string row : rows) {
            ans += row;
        }

        return ans;
    }
};
```

---

## 解題想法

這題可以用模擬法處理。

建立 `numRows` 個字串，代表 Zigzag 的每一列。  
接著用 `currentRow` 紀錄目前字元要放在哪一列，用 `direction` 紀錄目前方向。

規則如下：

1. 從第 0 列開始往下放字元。
2. 到最後一列時，方向改成往上。
3. 回到第 0 列時，方向改成往下。
4. 重複這個過程直到所有字元都放完。
5. 最後把每一列的字串接起來，就是答案。

---

## 心得

這題的重點不是複雜演算法，而是要正確理解 Zigzag 的移動方式。

一開始如果只想用固定間隔去取字元，很容易漏掉斜線方向的字元。  
用模擬法比較直覺，只要記錄目前在哪一列，以及現在是往下還是往上，就可以把整個 Zigzag 過程完整做出來。

這題讓我練習到字串處理、陣列儲存，以及模擬題中方向變化的寫法。
