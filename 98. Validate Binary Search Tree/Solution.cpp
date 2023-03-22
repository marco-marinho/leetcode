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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool res = validate(root, INT_MIN - 1L, INT_MAX + 1L);
        return res;
    }
    bool validate(TreeNode* root, long long minv, long long maxv){
        if (!root) return true;
        bool left = !root->left || root->left->val < root->val;
        bool right = !root->right || root->right->val > root->val;

        bool constrains = root->val > minv && root->val < maxv;
        if (root->right){
            right = right && validate(root->right, max(minv, (long long) root->val), maxv);
        }
        if (root->left) {
            left = left && validate(root->left, minv, min((long long) root->val, maxv));
        }
        return right && left && constrains;
    }
};
