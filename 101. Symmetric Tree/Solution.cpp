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
        stack<TreeNode*> toVisit;
        toVisit.push(root);
        while(!toVisit.empty()){
            vector<int> level;
            stack<TreeNode*> nextToVisit;
            while(!toVisit.empty()){
                auto curr = toVisit.top();
                toVisit.pop();
                if (!curr) {
                    level.emplace_back(INT_MAX);
                    continue;
                }
                level.emplace_back(curr->val);
                nextToVisit.push(curr->left);
                nextToVisit.push(curr->right);
            }
            if (!isSymetric(level)) return false;
            toVisit = nextToVisit;
        }
        return true;
    }

    bool isSymetric(vector<int> vec){
        int size = vec.size() % 2 == 0 ? vec.size() / 2 : (vec.size() + 1) / 2;
        for (int i = 0; i < size; i++){
            if (vec[i] != vec[vec.size() - 1 - i]) return false;
        }
        return true;
    }
};
