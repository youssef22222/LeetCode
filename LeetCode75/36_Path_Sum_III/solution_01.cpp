/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* node, int targetSum, long long curSum) {
        if (node == nullptr) {
            return 0;
        }
        return (dfs(node->left, targetSum, curSum + node->val) +
                dfs(node->right, targetSum, curSum + node->val) +
                (curSum + node->val == targetSum));
    }
    int count(TreeNode* node, int targetSum) {
        if (node == nullptr) {
            return 0;
        }
        return dfs(node, targetSum, 0) + count(node->left, targetSum) +
               count(node->right, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        // suppose each node is a root node start sum from each node
        return count(root, targetSum);
    }
};
