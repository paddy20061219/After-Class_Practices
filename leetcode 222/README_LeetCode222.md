# LeetCode 222 - Count Complete Tree Nodes

## 題目重點

這題要計算一棵 complete binary tree 裡面有幾個節點。

Complete binary tree 的意思是：

```txt
除了最後一層以外，每一層都是滿的
最後一層的節點會盡量靠左排列
```

題目要求回傳整棵樹的節點數。

例如：

```txt
Input: root = [1,2,3,4,5,6]
Output: 6
```

因為這棵樹總共有 6 個節點。

這題可以直接 DFS 算全部節點，但題目是 complete binary tree，所以可以利用它的性質做得更快。

---

## 錯誤程式碼

```cpp
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
```

---

## 錯誤原因

錯誤程式碼只沿著左邊一路往下走，算出來的是左邊高度，不是整棵樹的節點數。

例如：

```txt
root = [1,2,3,4,5,6]
```

這棵樹長得大概是：

```txt
      1
    /   \
   2     3
  / \   /
 4   5 6
```

錯誤程式碼只會走：

```txt
1 -> 2 -> 4
```

所以會回傳：

```txt
3
```

但正確答案應該是：

```txt
6
```

所以只看左邊路徑一定會漏掉右子樹和其他節點。

---

## 正確程式碼

```cpp
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
```

---

## 解題想法

這題可以利用 complete binary tree 的特性。

對一棵子樹來說，如果：

```txt
一路往左的高度 == 一路往右的高度
```

代表這棵子樹其實是滿二元樹。

滿二元樹的節點數可以直接用公式算：

```txt
2^height - 1
```

在程式裡可以寫成：

```cpp
(1 << height) - 1
```

如果左右高度不一樣，就代表這棵子樹不是滿的。  
這時候就繼續遞迴算：

```cpp
1 + countNodes(root->left) + countNodes(root->right)
```

其中 `1` 是目前 root 節點。

這樣就不用每次都真的把全部節點走完，遇到滿二元樹時可以直接用公式算出節點數。

---

## 心得

這題如果用普通 DFS，其實概念很簡單，就是左子樹加右子樹再加 1。

但題目特別給 complete binary tree，所以可以利用它的結構。  
我覺得這題的重點是判斷一棵子樹是不是滿二元樹，如果是，就不用繼續往下數。

這題讓我比較理解 complete binary tree 和 full binary tree 的差別，也練習到用樹的高度來減少遞迴次數。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
