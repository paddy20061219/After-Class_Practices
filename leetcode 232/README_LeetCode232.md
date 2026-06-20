# LeetCode 232 - Implement Queue using Stacks

## 題目重點

這題要用 stack 來實作 queue。

Queue 的特性是：

```txt
先進先出 FIFO
```

也就是最早放進去的元素，要最早被拿出來。

但是 stack 的特性是：

```txt
後進先出 LIFO
```

所以不能直接用一個 stack 來當 queue，不然順序會反過來。

題目要實作的功能有：

```cpp
push(x)
pop()
peek()
empty()
```

例如：

```txt
push(1)
push(2)
peek() -> 1
pop()  -> 1
empty() -> false
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <stack>
using namespace std;

// LeetCode 232 - Implement Queue using Stacks
// Wrong version: this code is intentionally incorrect.

class MyQueue {
private:
    stack<int> st;

public:
    MyQueue() {
    }

    void push(int x) {
        st.push(x);
    }

    int pop() {
        // 錯誤想法：直接從 stack 最上面拿出來
        // 但 stack 是後進先出，queue 應該是先進先出。
        int value = st.top();
        st.pop();
        return value;
    }

    int peek() {
        return st.top();
    }

    bool empty() {
        return st.empty();
    }
};
```

---

## 錯誤原因

錯誤程式碼只用一個 stack，然後 `pop()` 和 `peek()` 都直接看 stack 最上面的元素。

但是 stack 是後進先出，最後放進去的會最先被拿出來。  
queue 則是先進先出，最早放進去的要先被拿出來。

例如：

```txt
push(1)
push(2)
```

queue 的順序應該是：

```txt
1, 2
```

所以：

```txt
pop() 應該回傳 1
```

但錯誤程式碼用 stack，最上面是 `2`，所以它會回傳：

```txt
2
```

這就變成 stack，不是 queue 了。

---

## 正確程式碼

```cpp
#include <iostream>
#include <stack>
using namespace std;

// LeetCode 232 - Implement Queue using Stacks
// Correct version

class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

    void moveToOutStack() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() {
    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        moveToOutStack();

        int value = outStack.top();
        outStack.pop();

        return value;
    }

    int peek() {
        moveToOutStack();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
```

---

## 解題想法

這題可以用兩個 stack 來模擬 queue。

我使用：

```cpp
inStack
outStack
```

`inStack` 負責放新加入的元素。  
`outStack` 負責拿出最前面的元素。

當呼叫 `push(x)` 時，直接把 `x` 放進 `inStack`。

當呼叫 `pop()` 或 `peek()` 時，如果 `outStack` 是空的，就把 `inStack` 裡面的元素全部倒進 `outStack`。

例如：

```txt
inStack: 1, 2, 3
```

倒到 `outStack` 之後會變成：

```txt
outStack: 3, 2, 1
```

這時候 `outStack.top()` 就會是最早加入的 `1`，剛好符合 queue 的先進先出。

如果 `outStack` 還有元素，就不用再倒一次，直接使用即可。

---

## 心得

這題主要是在理解 stack 和 queue 的差別。

一開始如果直接用一個 stack，寫起來很簡單，可是順序會變成後進先出，跟 queue 的規則相反。

用兩個 stack 可以把順序反轉回來。這題讓我比較清楚資料結構的特性，也知道怎麼用一種資料結構去模擬另一種資料結構。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
