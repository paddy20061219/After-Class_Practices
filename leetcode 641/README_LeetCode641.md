# LeetCode 641 - Design Circular Deque

## 題目重點

這題要設計一個 circular deque，也就是循環雙端佇列。

Deque 的特色是兩邊都可以操作：

```txt
前端可以插入、刪除
後端也可以插入、刪除
```

題目要實作這些功能：

```cpp
MyCircularDeque(k)
insertFront(value)
insertLast(value)
deleteFront()
deleteLast()
getFront()
getRear()
isEmpty()
isFull()
```

跟普通 queue 不一樣，這題前面和後面都要能加資料、刪資料。  
而且因為是 circular deque，所以空出來的位置之後要可以被重複使用。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 641 - Design Circular Deque
// Wrong version: this code is intentionally incorrect.

class MyCircularDeque {
private:
    vector<int> data;
    int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
    }

    bool insertFront(int value) {
        // 錯誤做法：用 vector insert 模擬插入前端
        // 這不是 circular deque 的真正做法，而且會搬動很多元素。
        if (data.size() == capacity) {
            return false;
        }

        data.insert(data.begin(), value);
        return true;
    }

    bool insertLast(int value) {
        if (data.size() == capacity) {
            return false;
        }

        data.push_back(value);
        return true;
    }

    bool deleteFront() {
        if (data.empty()) {
            return false;
        }

        data.erase(data.begin());
        return true;
    }

    bool deleteLast() {
        if (data.empty()) {
            return false;
        }

        data.pop_back();
        return true;
    }

    int getFront() {
        if (data.empty()) {
            return -1;
        }

        return data[0];
    }

    int getRear() {
        if (data.empty()) {
            return -1;
        }

        return data[data.size() - 1];
    }

    bool isEmpty() {
        return data.empty();
    }

    bool isFull() {
        return data.size() == capacity;
    }
};
```

---

## 錯誤原因

錯誤程式碼雖然功能看起來有做出來，但它其實不是 circular deque 的設計方式。

問題主要在這兩行：

```cpp
data.insert(data.begin(), value);
data.erase(data.begin());
```

這樣每次在前面插入或刪除，都會讓後面的元素搬動。  
這不符合 circular deque 用固定陣列和 index 繞圈的想法。

Circular deque 應該是用固定大小的陣列，然後用 `frontIndex` 和 `rearIndex` 紀錄前端和後端位置。

如果前端要往前移，就用：

```cpp
(frontIndex - 1 + capacity) % capacity
```

如果後端要往後移，就用：

```cpp
(rearIndex + 1) % capacity
```

這樣才可以重複利用陣列空間，而不是一直搬動元素。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 641 - Design Circular Deque
// Correct version

class MyCircularDeque {
private:
    vector<int> data;
    int frontIndex;
    int rearIndex;
    int currentSize;
    int capacity;

public:
    MyCircularDeque(int k) {
        data.resize(k);
        capacity = k;
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = 0;
        } else {
            frontIndex = (frontIndex - 1 + capacity) % capacity;
        }

        data[frontIndex] = value;
        currentSize++;

        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = 0;
        } else {
            rearIndex = (rearIndex + 1) % capacity;
        }

        data[rearIndex] = value;
        currentSize++;

        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        if (currentSize == 1) {
            currentSize--;
            return true;
        }

        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;

        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        if (currentSize == 1) {
            currentSize--;
            return true;
        }

        rearIndex = (rearIndex - 1 + capacity) % capacity;
        currentSize--;

        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return data[frontIndex];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return data[rearIndex];
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == capacity;
    }
};
```

---

## 解題想法

這題可以用固定大小的 `vector` 加上兩個 index 來做。

需要記錄：

```cpp
frontIndex
rearIndex
currentSize
capacity
```

`frontIndex` 表示目前最前面的元素位置。  
`rearIndex` 表示目前最後面的元素位置。  
`currentSize` 用來判斷現在有幾個元素。

插入前端時，如果 deque 不是空的，就讓 front 往前一格：

```cpp
frontIndex = (frontIndex - 1 + capacity) % capacity;
```

加上 `capacity` 是為了避免變成負數。

插入後端時，就讓 rear 往後一格：

```cpp
rearIndex = (rearIndex + 1) % capacity;
```

刪除前端時，front 往後走。  
刪除後端時，rear 往前走。

這樣前後都可以操作，而且 index 到底之後可以繞回來。

---

## 心得

這題跟 LeetCode 622 circular queue 很像，但這題是 deque，所以前後兩端都要能操作。

我覺得比較容易錯的地方是前端往前移的寫法：

```cpp
(frontIndex - 1 + capacity) % capacity
```

如果忘記加 `capacity`，index 可能會變成負數。

這題讓我更清楚 circular 的概念，其實不是一直刪除或插入 vector，而是讓 index 在固定陣列裡面繞圈。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
