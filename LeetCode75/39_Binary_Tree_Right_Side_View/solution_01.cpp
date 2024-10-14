/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    const int sz=101;
    const int defaultValue=-200;
public:
    void dfsOnRightSide(TreeNode* node,int depth,vector<int>& rightNodes){
         if(node==nullptr){
            return;
         }
         if(rightNodes[depth]==defaultValue){
            rightNodes[depth]=node->val;
         }
         dfsOnRightSide(node->right,depth+1,rightNodes);
         dfsOnRightSide(node->left,depth+1,rightNodes);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>rightNodes(sz,defaultValue);
        dfsOnRightSide(root,0,rightNodes);
        while(rightNodes.size() && rightNodes.back()==defaultValue){
            rightNodes.pop_back();
        }
        return rightNodes;
    }
};