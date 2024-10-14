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
    int dfs(TreeNode* root, int maximumValue) {
        if (root == nullptr) {
            return 0;
        }
        int mx = max(maximumValue, root->val);
        return dfs(root->right, mx) + dfs(root->left, mx) +
               (root->val >= maximumValue);
    }
    int goodNodes(TreeNode* root) { return dfs(root, -1e5); }
};