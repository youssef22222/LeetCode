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
    int count(TreeNode* node, int length, bool lastWasLeft) {
        if (node == nullptr) {
            return length;
        }
        int mx = 0;
        if (lastWasLeft) {
            mx = max(mx, count(node->right, length + 1, 0));
            mx = max(mx, count(node->left, 0, 1));
        } else {
            mx = max(mx, count(node->left, length + 1, 1));
            mx = max(mx, count(node->right, 0, 0));
        }

        return mx;
    }
    int longestZigZag(TreeNode* root) {
        return max(count(root->left, 0, 1), count(root->right, 0, 0));
    }
};
