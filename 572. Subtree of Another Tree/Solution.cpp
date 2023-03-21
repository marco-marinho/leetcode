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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        else if (!root || !subRoot) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto next = q.front();
            q.pop();
            if (next && next->val == subRoot->val) {
                bool check = areEqual(next, subRoot);
                if (check) return true;
            } 
            if (next->left) q.push(next->left);
            if (next->right) q.push(next->right);
        }
        return false;
    }
    bool areEqual(TreeNode* node, TreeNode* subRoot) {
        if (!node && !subRoot) return true;
        else if(!node || !subRoot) return false;
        if (node->val != subRoot->val) return false;
        return areEqual(node->left, subRoot->left) && areEqual(node->right, subRoot->right);
    }
};