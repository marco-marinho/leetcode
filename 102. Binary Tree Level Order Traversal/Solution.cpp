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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        if (!root) return output;
        queue<TreeNode*> pqueue;
        pqueue.push(root);
        output.push_back({root->val});
        while(!pqueue.empty()){
            vector<int> buff;
            queue<TreeNode*> next_queue;
            while(!pqueue.empty()){
            auto next = pqueue.front();
            pqueue.pop();
            if (next->left){
                buff.push_back(next->left->val);
                next_queue.push(next->left);
            }
            if (next->right){
                buff.push_back(next->right->val);
                next_queue.push(next->right);
            }
            }
            if (!buff.empty()) output.push_back(buff);
            pqueue=next_queue;
        }
        return output;
    }
};