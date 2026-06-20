# LeetCode 9 - Palindrome Number 訂正

## 題目重點

這題要判斷一個整數 `x` 是否為回文數。

回文數的意思是：從左到右讀和從右到左讀都一樣。

例如：

```txt
121 是回文數
123 不是回文數
-121 不是回文數
10 不是回文數
```

需要注意：

1. 負數一定不是回文數，因為前面有負號。
2. 個位數一定是回文數。
3. 結尾是 0 的數字通常不是回文數，除非這個數字本身就是 0。
4. 可以用反轉數字的方式判斷，但要小心整數溢位。

## 錯誤程式碼

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return true;
        return x % 10 == x / 10;
    }
};
```

## 錯誤原因

這份錯誤程式有很多問題：

1. 負數判斷錯誤  
   `-121` 應該不是回文數，因為有負號，但是程式卻直接回傳 `true`。

2. 只比較最後一位和 `x / 10`  
   `x % 10` 只會得到個位數，`x / 10` 會拿掉個位數，這兩個東西不能用來判斷整個數字是否回文。

3. 無法處理多位數  
   例如 `121`：

   ```txt
   x % 10 = 1
   x / 10 = 12
   1 == 12 是 false
   ```

   但 `121` 明明是回文數。

所以這份程式會得到錯誤答案。

## 正確程式碼

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x != 0 && x % 10 == 0) return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        return x == reversedHalf || x == reversedHalf / 10;
    }
};
```

## 正確解法說明

這題可以只反轉數字的一半，避免整數溢位。

例如 `1221`：

```txt
原本 x = 1221, reversedHalf = 0
取出 1，x = 122, reversedHalf = 1
取出 2，x = 12, reversedHalf = 12
```

此時 `x == reversedHalf`，所以 `1221` 是回文數。

例如 `121`：

```txt
原本 x = 121, reversedHalf = 0
取出 1，x = 12, reversedHalf = 1
取出 2，x = 1, reversedHalf = 12
```

因為位數是奇數，中間那一位不需要比較，所以用：

```cpp
x == reversedHalf / 10
```

來判斷。

## 心得

這題看起來很簡單，但如果直接把整個數字反轉，可能會有整數溢位的問題。

比較好的做法是只反轉後半段數字，這樣不但比較安全，也比較有效率。

這題也提醒我要先處理特殊情況，例如負數和結尾是 0 的數字，否則很容易出現 Wrong Answer。
