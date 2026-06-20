# LeetCode 150 - Evaluate Reverse Polish Notation

## 題目重點

這題要計算 Reverse Polish Notation，也就是反向波蘭表示法。

一般算式可能長這樣：

```txt
(2 + 1) * 3
```

用 RPN 表示會變成：

```txt
2 1 + 3 *
```

題目會給一個字串陣列 `tokens`，裡面可能是數字，也可能是運算子：

```txt
+
-
*
/
```

要照 RPN 的規則算出最後結果。

例如：

```txt
Input: tokens = ["2","1","+","3","*"]
Output: 9
```

因為：

```txt
2 + 1 = 3
3 * 3 = 9
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// LeetCode 150 - Evaluate Reverse Polish Notation
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                // 錯誤想法：直接用 a - b、a / b
                // 但 RPN 中先 pop 出來的是右運算元，順序不能亂。
                if (token == "+") {
                    st.push(a + b);
                } else if (token == "-") {
                    st.push(a - b);
                } else if (token == "*") {
                    st.push(a * b);
                } else {
                    st.push(a / b);
                }
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
```

---

## 錯誤原因

錯誤程式碼雖然有使用 stack，但是在做減法和除法時，把左右運算元的順序弄反了。

在 RPN 裡遇到運算子時，要從 stack 拿出兩個數字：

```txt
第一個 pop 出來的是右邊的數
第二個 pop 出來的是左邊的數
```

所以如果 tokens 是：

```txt
["4","13","5","/","+"]
```

遇到 `/` 時，stack 裡面會有：

```txt
4, 13, 5
```

應該要算：

```txt
13 / 5
```

不是：

```txt
5 / 13
```

加法和乘法順序反過來通常沒差，但減法和除法順序一反就會錯。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// LeetCode 150 - Evaluate Reverse Polish Notation
// Correct version

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int right = st.top();
                st.pop();

                int left = st.top();
                st.pop();

                if (token == "+") {
                    st.push(left + right);
                } else if (token == "-") {
                    st.push(left - right);
                } else if (token == "*") {
                    st.push(left * right);
                } else {
                    st.push(left / right);
                }
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
```

---

## 解題想法

這題適合用 stack。

因為 RPN 的規則是：

1. 遇到數字就先放進 stack。
2. 遇到運算子，就從 stack 拿出兩個數字來計算。
3. 計算完的結果再放回 stack。
4. 最後 stack 裡剩下的那個數字就是答案。

比較容易錯的是運算順序。

假設 pop 出來的兩個數字是：

```cpp
int right = st.top();
st.pop();

int left = st.top();
st.pop();
```

那真正要算的是：

```txt
left operator right
```

不是：

```txt
right operator left
```

尤其是 `-` 和 `/`，順序錯了答案就會不一樣。

---

## 心得

這題讓我更熟悉 stack 的使用方式。

RPN 題目其實沒有很複雜，重點是看到數字就存起來，看到運算子就拿出前面的數字計算。  
但這題也提醒我，從 stack 拿資料時順序要很小心，因為 stack 是後進先出，第一個拿出來的不一定是算式左邊的數。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
