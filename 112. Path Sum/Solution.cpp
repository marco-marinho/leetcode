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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return hasPathSum(root, 0, targetSum);
    }
    bool hasPathSum(TreeNode* root,  int sumSoFar, int targetSum){
        int val = sumSoFar + root->val;
        if (!root->left && !root->right && val == targetSum) return true;
        bool found = false;
        if (root->left) found = found || hasPathSum(root->left, val, targetSum);
        if (root->right) found = found || hasPathSum(root->right, val, targetSum);
        return found;
    }
};
