# LeetCode 148 - Sort List

## 題目重點

這題給一個 linked list 的頭節點 `head`，要把整個 linked list 依照節點數值由小到大排序。

題目要求：

1. 回傳排序後 linked list 的頭節點。
2. 不能只處理陣列，要操作 linked list。
3. 目標時間複雜度是 `O(n log n)`。
4. 適合使用 merge sort，因為 linked list 很適合做切半和合併。

例如：

```txt
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

再例如：

```txt
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```

---

## 錯誤程式碼

```cpp
#include <iostream>
using namespace std;

// LeetCode 148 - Sort List
// Wrong version: this code is intentionally incorrect.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        // 錯誤想法：只掃描一次，相鄰兩個節點如果順序錯就交換數值
        // 但只做一輪並不能保證整個 linked list 完全排序。
        ListNode* cur = head;

        while (cur != nullptr && cur->next != nullptr) {
            if (cur->val > cur->next->val) {
                swap(cur->val, cur->next->val);
            }
            cur = cur->next;
        }

        return head;
    }
};
```

---

## 錯誤原因

錯誤程式碼只掃描 linked list 一次，遇到相鄰節點順序錯誤時就交換兩個節點的值。

這很像只做一輪 bubble sort，但是只做一輪不能保證整個 linked list 都排序完成。

例如：

```txt
Input: [4,2,1,3]
```

錯誤程式碼處理過程大概會變成：

```txt
[2,1,3,4]
```

但是正確答案應該是：

```txt
[1,2,3,4]
```

因為 `1` 還需要繼續往前移動，但程式只掃描一次就結束了。

所以這個做法不能保證排序完成。

---

## 正確程式碼

```cpp
#include <iostream>
using namespace std;

// LeetCode 148 - Sort List
// Correct version

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 1. 用快慢指標把 linked list 切成兩半
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rightHead = slow->next;
        slow->next = nullptr;

        // 2. 分別排序左右兩半
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        // 3. 合併兩個已排序 linked list
        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }

            tail = tail->next;
        }

        if (a != nullptr) {
            tail->next = a;
        } else {
            tail->next = b;
        }

        return dummy.next;
    }
};
```

---

## 解題想法

這題適合用 merge sort。

Merge sort 的概念是：

1. 把 linked list 切成左右兩半。
2. 分別把左右兩半排序好。
3. 再把兩個排序好的 linked list 合併起來。

在 linked list 裡切半可以用快慢指標：

```txt
slow 每次走一步
fast 每次走兩步
```

當 `fast` 走到底時，`slow` 大約會停在中間位置。  
接著把 `slow->next` 切開，就可以把 linked list 分成兩半。

合併時使用一個 dummy node，讓接節點的過程比較簡單。

---

## 心得

這題的重點是 linked list 排序不能只用簡單交換一次處理。

如果只是掃描一次，最多只能修正一部分相鄰順序，不能保證整體排序完成。  
使用 merge sort 比較適合 linked list，因為 linked list 不需要像陣列一樣搬動大量元素，只要改變節點指標就可以完成合併。

這題讓我練習到快慢指標、linked list 切半，以及合併兩個排序 linked list 的寫法。
