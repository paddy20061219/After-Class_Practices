# LeetCode 622 - Design Circular Queue

## 題目重點

這題要自己設計一個 circular queue，也就是循環佇列。

Queue 的基本規則是：

```txt
先進先出 FIFO
```

但 circular queue 的重點是，當後面的位置用完後，如果前面因為 `deQueue()` 空出位置，就可以繞回前面繼續使用。

題目要實作這些功能：

```cpp
MyCircularQueue(k)
enQueue(value)
deQueue()
Front()
Rear()
isEmpty()
isFull()
```

例如 queue 大小是 3：

```txt
enQueue(1)
enQueue(2)
enQueue(3)
isFull() -> true
deQueue()
enQueue(4)
Rear() -> 4
```

這裡 `4` 可以放進去，是因為前面有一格被 `deQueue()` 空出來了。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 622 - Design Circular Queue
// Wrong version: this code is intentionally incorrect.

class MyCircularQueue {
private:
    vector<int> data;
    int capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
    }

    bool enQueue(int value) {
        // 錯誤想法：只要 vector 還沒滿就 push_back
        // 但沒有真正做 circular queue，也沒有重複利用前面空出來的位置。
        if (data.size() == capacity) {
            return false;
        }

        data.push_back(value);
        return true;
    }

    bool deQueue() {
        if (data.empty()) {
            return false;
        }

        // 錯誤做法：直接刪除第一個元素
        // erase 不是 circular queue 的做法，而且效率也不好。
        data.erase(data.begin());
        return true;
    }

    int Front() {
        if (data.empty()) {
            return -1;
        }

        return data[0];
    }

    int Rear() {
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

錯誤程式碼只是用 `vector` 模擬普通 queue，沒有真正做到 circular queue。

最大的問題是：

```cpp
data.erase(data.begin());
```

這樣雖然可以刪掉第一個元素，但它會讓後面的元素全部往前搬，這不是循環佇列的設計方式。

Circular queue 應該要用固定大小的陣列，然後用 index 移動來表示 front 和 rear。

例如大小是 3：

```txt
[1, 2, 3]
```

如果 `deQueue()` 移除 `1`，前面那格應該可以之後被重複利用。

正確做法不是一直刪除陣列元素，而是讓 `frontIndex` 往後移動。  
如果走到陣列尾端，就用 `% capacity` 繞回前面。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 622 - Design Circular Queue
// Correct version

class MyCircularQueue {
private:
    vector<int> data;
    int frontIndex;
    int rearIndex;
    int currentSize;
    int capacity;

public:
    MyCircularQueue(int k) {
        data.resize(k);
        capacity = k;
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        rearIndex = (rearIndex + 1) % capacity;
        data[rearIndex] = value;
        currentSize++;

        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;

        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return data[frontIndex];
    }

    int Rear() {
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

這題用固定大小的 `vector` 來做 circular queue。

需要記錄幾個變數：

```cpp
frontIndex   // 目前隊伍最前面的 index
rearIndex    // 目前隊伍最後面的 index
currentSize  // 現在 queue 裡有幾個元素
capacity     // queue 最大容量
```

新增元素時：

```cpp
rearIndex = (rearIndex + 1) % capacity;
```

這樣如果 `rearIndex` 到了最後一格，再往後就會回到 0。

刪除元素時：

```cpp
frontIndex = (frontIndex + 1) % capacity;
```

這樣 front 也可以循環移動。

判斷空和滿則用 `currentSize`：

```cpp
currentSize == 0        // empty
currentSize == capacity // full
```

我覺得用 `currentSize` 比較好懂，因為不用再額外空一格來區分滿和空。

---

## 心得

這題主要是在練 queue 的底層實作。

一開始如果用 `vector.push_back()` 和 `erase()`，看起來好像可以做到 queue，但其實沒有 circular 的概念，也沒有固定大小重複利用空間。

Circular queue 的重點是 index 繞圈，所以 `% capacity` 很重要。  
這題讓我比較理解為什麼佇列不一定要真的刪掉資料，有時候只要移動 front 和 rear 的位置就可以了。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
