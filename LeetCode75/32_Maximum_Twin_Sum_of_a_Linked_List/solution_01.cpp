/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void getMx(ListNode* node, vector<int>& val) {
        if (node == nullptr) {
            return;
        }
        val.push_back(node->val);
        getMx(node->next, val);
    }
    int pairSum(ListNode* head) {
        vector<int> val;
        getMx(head, val);
        int len = val.size();
        int mxTwin = 0;
        for (int i = 0; i < len / 2; i++) {
            mxTwin = max(mxTwin, val[i] + val[len - i - 1]);
        }
        return mxTwin;
    }
};