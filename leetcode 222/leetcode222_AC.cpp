#include <iostream>
using namespace std;

// LeetCode 222 - Count Complete Tree Nodes
// Correct version

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

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        // 如果左右高度一樣，代表這棵子樹是滿二元樹
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }

        // 否則繼續遞迴計算左右子樹
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int getLeftHeight(TreeNode* node) {
        int height = 0;

        while (node != nullptr) {
            height++;
            node = node->left;
        }

        return height;
    }

    int getRightHeight(TreeNode* node) {
        int height = 0;

        while (node != nullptr) {
            height++;
            node = node->right;
        }

        return height;
    }
};
