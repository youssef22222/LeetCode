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
    TreeNode* dfs(TreeNode* node, TreeNode* firstNode, TreeNode* secondNode) {
        if (node == nullptr || node == firstNode || node == secondNode) {
            return node;
        }
        TreeNode* leftNode = dfs(node->left, firstNode, secondNode);
        TreeNode* rightNode = dfs(node->right, firstNode, secondNode);
        if (leftNode != nullptr && rightNode != nullptr) {
            return node;
        } else {
            return ((leftNode != nullptr) ? leftNode : rightNode);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};