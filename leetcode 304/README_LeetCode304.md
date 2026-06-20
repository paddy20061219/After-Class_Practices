# LeetCode 304 - Range Sum Query 2D - Immutable

## 題目重點

這題是 LeetCode 303 的二維版本。

題目會給一個二維矩陣 `matrix`，然後要多次查詢某個矩形範圍內的總和。

查詢格式是：

```txt
sumRegion(row1, col1, row2, col2)
```

意思是要算從左上角：

```txt
(row1, col1)
```

到右下角：

```txt
(row2, col2)
```

這個矩形裡所有數字的總和。

例如：

```txt
matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]
```

如果查詢：

```txt
sumRegion(2, 1, 4, 3)
```

就是要算第 2 列到第 4 列、第 1 欄到第 3 欄的總和。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 304 - Range Sum Query 2D - Immutable
// Wrong version: this code is intentionally incorrect.

class NumMatrix {
private:
    vector<vector<int>> matrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;

        // 錯誤想法：只加 row1 這一列
        // 但題目要求的是 row1 到 row2、col1 到 col2 的整個矩形範圍。
        for (int col = col1; col <= col2; col++) {
            sum += matrix[row1][col];
        }

        return sum;
    }
};
```

---

## 錯誤原因

錯誤程式碼只加了 `row1` 這一列的數字。

但是題目要算的是一個矩形範圍，不是單獨一列。

例如查詢：

```txt
sumRegion(2, 1, 4, 3)
```

代表要算：

```txt
row 2 到 row 4
col 1 到 col 3
```

也就是多列多欄的範圍。

錯誤程式碼只會算：

```txt
matrix[2][1] + matrix[2][2] + matrix[2][3]
```

可是它漏掉了第 3 列和第 4 列的資料，所以答案會錯。

另外，如果每次查詢都用雙層迴圈去加總，雖然直覺，但查詢很多次時效率會比較差。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 304 - Range Sum Query 2D - Immutable
// Correct version

class NumMatrix {
private:
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        prefix.assign(m + 1, vector<int>(n + 1, 0));

        // prefix[i][j] 表示從 (0,0) 到 (i-1,j-1) 的矩形總和
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = matrix[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1]
             - prefix[row1][col2 + 1]
             - prefix[row2 + 1][col1]
             + prefix[row1][col1];
    }
};
```

---

## 解題想法

這題可以用二維前綴和。

一維前綴和是先存前面累積的總和，這題只是變成矩形範圍。

我建立一個 `prefix`，大小比原本矩陣多一列、多一欄：

```cpp
prefix.assign(m + 1, vector<int>(n + 1, 0));
```

這樣可以少處理很多邊界問題。

`prefix[i][j]` 代表：

```txt
從 matrix[0][0] 到 matrix[i-1][j-1] 的矩形總和
```

建立方式是：

```cpp
prefix[i][j] = matrix[i - 1][j - 1]
             + prefix[i - 1][j]
             + prefix[i][j - 1]
             - prefix[i - 1][j - 1];
```

最後查詢矩形總和時，用大矩形扣掉上面和左邊多出來的部分，再加回被扣兩次的左上角：

```cpp
prefix[row2 + 1][col2 + 1]
- prefix[row1][col2 + 1]
- prefix[row2 + 1][col1]
+ prefix[row1][col1]
```

---

## 心得

這題一開始看起來只是把範圍內的數字加起來，但如果查詢很多次，每次都重新加會比較慢。

用二維前綴和可以先把累積資訊算好，之後每次查詢都只要用四個位置就能算出答案。

我覺得這題比較容易搞混的是 `+1` 的 index，因為 `prefix` 比原本矩陣多一排和一欄。只要記得 `prefix[i][j]` 對應到 `matrix[i-1][j-1]`，就比較不會亂掉。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
