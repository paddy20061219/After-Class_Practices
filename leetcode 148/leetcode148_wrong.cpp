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
