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

    static int longestZigZag(TreeNode* root) noexcept {
        int maxSteps = 0;
        zigZag(root, false, 0, maxSteps);
        zigZag(root, true, 0, maxSteps);
        return maxSteps;
    }

private:

    static void zigZag(TreeNode* node, bool left, int steps, int &maxSteps) noexcept {
        if (!node) return;
        maxSteps = max(maxSteps, steps);
        if (left) {
            zigZag(node->left, false, steps + 1, maxSteps);
            zigZag(node->right, true, 1, maxSteps);
        } else {
            zigZag(node->left, false, 1, maxSteps);
            zigZag(node->right, true, steps + 1, maxSteps);
        }
    }

};
