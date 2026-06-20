# LeetCode 326 - Power of Three

## 題目重點

這題要判斷一個整數 `n` 是不是 3 的次方。

也就是判斷 `n` 是否可以表示成：

```txt
3^x
```

其中 `x` 是非負整數。

例如：

```txt
Input: n = 27
Output: true
```

因為：

```txt
27 = 3^3
```

再例如：

```txt
Input: n = 45
Output: false
```

雖然 45 可以被 3 整除，但是它不是 3 的次方。

---

## 錯誤程式碼

```cpp
#include <iostream>
using namespace std;

// LeetCode 326 - Power of Three
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    bool isPowerOfThree(int n) {
        // 錯誤想法：只要可以被 3 整除，就當成 3 的次方
        if (n <= 0) {
            return false;
        }

        return n % 3 == 0;
    }
};
```

---

## 錯誤原因

錯誤程式碼只判斷 `n` 能不能被 3 整除。

但是「能被 3 整除」不代表「一定是 3 的次方」。

例如：

```txt
Input: n = 45
Wrong Output: true
Correct Output: false
```

因為：

```txt
45 = 3 × 15
```

但是 15 不是 3 的次方，所以 45 也不是 3 的次方。

另外還有一個特殊情況：

```txt
Input: n = 1
Correct Output: true
```

因為：

```txt
1 = 3^0
```

錯誤程式碼會判斷 `1 % 3 != 0`，所以會錯誤回傳 `false`。

---

## 正確程式碼

```cpp
#include <iostream>
using namespace std;

// LeetCode 326 - Power of Three
// Correct version

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }

        // 不斷除以 3
        while (n % 3 == 0) {
            n /= 3;
        }

        // 如果最後變成 1，代表原本是 3 的次方
        return n == 1;
    }
};
```

---

## 解題想法

這題可以用反覆除以 3 的方式解。

如果一個數是 3 的次方，例如：

```txt
27 = 3^3
```

那它可以一直被 3 整除：

```txt
27 / 3 = 9
9 / 3 = 3
3 / 3 = 1
```

最後會變成 `1`。

所以做法是：

1. 如果 `n <= 0`，直接回傳 `false`。
2. 當 `n` 可以被 3 整除時，就一直讓 `n /= 3`。
3. 迴圈結束後，如果 `n == 1`，代表它是 3 的次方。
4. 否則就不是 3 的次方。

---

## 心得

這題看起來很簡單，但不能只判斷能不能被 3 整除。

真正的重點是要確認這個數是不是完全由 3 連乘組成。  
用一直除以 3 的方法很直覺，也適合初學者理解。

這題讓我學到，遇到「某個數的次方」這種題目時，可以反過來用除法一步一步把它還原成 1。
