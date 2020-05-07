// https://leetcode-cn.com/problems/subtree-of-another-tree/
// 朴素DFS，递归

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool isSameTree(TreeNode *s, TreeNode *t) {
        if (s && t) {
            return s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
        }
        return s == t;
    }

public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return isSameTree(s, t) || (s && (isSubtree(s->left, t) || isSubtree(s->right, t)));
    }
};
