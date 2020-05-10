// 二叉树的最近公共祖先
// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/

// 储存父节点法
// 相应地还有判别式法。

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
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, bool> hasParent;

    void travel(TreeNode *cur, TreeNode *prev) {
        if (cur == nullptr) {
            return;
        }
        travel(cur->left, cur);
        parent[cur] = prev;
        travel(cur->right, cur);
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        travel(root, nullptr);

        while (p != nullptr) {
            hasParent[p] = true;
            p = parent[p];
        }

        while (q != nullptr) {
            if (hasParent[q]) {
                return q;
            }
            q = parent[q];
        }
        return nullptr;
    }
};
