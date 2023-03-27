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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymetric(root->left, root->right);
    }

    bool isSymetric(TreeNode* first, TreeNode* second){
        if (!first && !second) return true;
        if ((!first && second) || (first && !second)) return false;
        if (first->val != second->val) return false;
        return isSymetric(first->left, second->right) && isSymetric(first->right, second->left);
    }
};
