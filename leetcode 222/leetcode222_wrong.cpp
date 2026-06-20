#include <iostream>
using namespace std;

// LeetCode 222 - Count Complete Tree Nodes
// Wrong version: this code is intentionally incorrect.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // 錯誤想法：只沿著左子樹一路往下數高度
        // 但題目要算的是整棵樹的節點數，不是樹的高度。
        int count = 0;
        TreeNode* cur = root;

        while (cur != nullptr) {
            count++;
            cur = cur->left;
        }

        return count;
    }
};
