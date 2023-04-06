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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        stack<TreeNode*> toVisit;
        toVisit.push(root);
        while(!toVisit.empty()){
            auto curr = toVisit.top();
            toVisit.pop();
            if (curr->left){
                if (!curr->left->left && !curr->left->right){
                    sum += curr->left->val;
                }
                else toVisit.push(curr->left);
            }
            if (curr->right) toVisit.push(curr->right);
        }
        return sum;
    }
};
