# LeetCode 125 - Valid Palindrome

## 題目重點

這題要判斷一個字串是不是回文。

但是題目有特別規定：

1. 只需要考慮英文字母和數字。
2. 其他符號、空白、標點符號都要忽略。
3. 英文字母大小寫視為相同。
4. 如果整理後的字串是回文，就回傳 `true`，否則回傳 `false`。

例如：

```txt
Input: "A man, a plan, a canal: Panama"
Output: true
```

因為忽略空白、符號，並把大小寫視為相同後，會變成：

```txt
amanaplanacanalpanama
```

這是一個回文。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <string>
using namespace std;

// LeetCode 125 - Valid Palindrome
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        // 錯誤想法：直接比較左右字元，沒有忽略符號，也沒有處理大小寫
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
```

---

## 錯誤原因

錯誤程式碼直接用原本字串的左右字元比較，但題目要求要忽略非英數字元，也要忽略大小寫。

例如：

```txt
Input: "A man, a plan, a canal: Panama"
Correct Output: true
```

錯誤程式碼一開始會比較：

```txt
'A' 和 'a'
```

因為大小寫不同，所以它會直接回傳 `false`。

另外，它也沒有跳過空白和標點符號，所以像逗號、冒號、空白都會影響判斷，導致答案錯誤。

---

## 正確程式碼

```cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// LeetCode 125 - Valid Palindrome
// Correct version

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // 跳過左邊不是英文字母或數字的字元
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // 跳過右邊不是英文字母或數字的字元
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // 比較時要忽略大小寫
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
```

---

## 解題想法

這題可以用雙指標解。

一開始讓 `left` 指向字串最左邊，`right` 指向字串最右邊。

每次比較前：

1. 如果 `left` 指到的字元不是英文字母或數字，就往右移。
2. 如果 `right` 指到的字元不是英文字母或數字，就往左移。
3. 兩邊都指到有效字元後，再把它們轉成小寫比較。
4. 如果不同，就不是回文。
5. 如果相同，就繼續往中間移動。

只要全部比較完都沒有出錯，就代表是回文。

---

## 心得

這題表面上是簡單的回文判斷，但重點其實是字串處理的細節。

一開始如果直接比較原字串，很容易因為空白、標點符號或大小寫不同而錯誤。  
正確做法是先理解題目規則，只比較英文字母和數字，並且比較時忽略大小寫。

這題讓我練習到雙指標的基本用法，也提醒我字串題常常要特別注意題目對字元的限制。
