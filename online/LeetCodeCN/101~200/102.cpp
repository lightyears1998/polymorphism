// 二叉树的层序遍历
// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

#include <queue>
#include <vector>
using namespace std;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que[2];
        que[0].push(root);

        vector<vector<int>> result;
        for (int level = 0; true; ++level) {
            queue<TreeNode*>& current_queue = que[level & 1];
            queue<TreeNode*>& next_queue = que[!(level & 1)];
            vector<int> current_level;

            while (current_queue.size() > 0) {
                TreeNode *node = current_queue.front();
                current_queue.pop();

                if (node) {
                    current_level.push_back(node->val);
                    next_queue.push(node->left);
                    next_queue.push(node->right);
                }
            }

            if (current_level.size() == 0) {
                break;
            }
            result.push_back(current_level);
        }

        return result;
    }
};
