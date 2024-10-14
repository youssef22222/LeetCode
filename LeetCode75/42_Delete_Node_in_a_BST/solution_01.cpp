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
    int getMinValueInRightSubTree(TreeNode* node) {
        if (node->left == nullptr) {
            return node->val;
        }
        return getMinValueInRightSubTree(node->left);
    }
    TreeNode* solve(TreeNode* node, int key) {
        if (node == nullptr) {
            return node;
        } else if (key < node->val) {
            node->left = solve(node->left, key);
        } else if (key > node->val) {
            node->right = solve(node->right, key);
        } else { // key==node->val
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            } else {
                int mnVal = getMinValueInRightSubTree(node->right);
                node->val = mnVal;
                node->right = solve(node->right, mnVal);
            }
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
       return solve(root,key);
    }
};
