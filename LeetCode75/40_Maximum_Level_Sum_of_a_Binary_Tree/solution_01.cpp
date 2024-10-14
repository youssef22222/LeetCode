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
    void dfs(TreeNode* node, int level, vector<int>& sum) {
        if (node == nullptr) {
            return;
        }
        if (sum.size() > level) {
            sum[level] += node->val;
        }
        else {
            sum.push_back(node->val);
        }
        dfs(node->right, level + 1, sum);
        dfs(node->left, level + 1, sum);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        dfs(root, 0, sum);
        int mxLevelSum = INT_MIN;
        int mxLevel;
        for (int i = 0; i < sum.size(); i++) {
            if (mxLevelSum < sum[i]) {
                mxLevelSum = sum[i];
                mxLevel = i + 1;
            }
        }
        return mxLevel;
    }
};