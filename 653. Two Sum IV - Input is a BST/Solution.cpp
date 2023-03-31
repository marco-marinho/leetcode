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
    set<int> values;
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (values.find(k - root->val) != values.end()) return true;
        values.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
