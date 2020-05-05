// https://leetcode-cn.com/problems/validate-binary-search-tree/
// 验证二叉搜索树

// 注意界限！

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
public:
    bool isValidBST(TreeNode* root) {
        // Get WA if use INT_MIN or INT_MAX:
        // number could be 2147483647.
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }

    bool isValidBST(TreeNode *root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        return isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
    }
};
