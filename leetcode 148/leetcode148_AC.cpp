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
