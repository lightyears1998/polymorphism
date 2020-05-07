// https://leetcode-cn.com/problems/subtree-of-another-tree/
// 朴素DFS

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
        stack<TreeNode*> nodes;
        nodes.push(s);

        while (nodes.size() > 0) {
            TreeNode* top = nodes.top();
            nodes.pop();

            if (top) {
                nodes.push(top->left);
                nodes.push(top->right);
                if (isSameTree(top, t)) {
                    return true;
                }
            }
        }
        return false;
    }
};
