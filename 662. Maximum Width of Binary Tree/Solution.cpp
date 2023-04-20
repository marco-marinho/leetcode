class Solution {
public:
    int widthOfBinaryTree(const TreeNode* root) {
        queue<pair<TreeNode*, uint64_t>> toVisit;
        toVisit.emplace(root, 0);
        uint64_t width = 0;
        while(!toVisit.empty()){
            width = max(width, toVisit.back().second - toVisit.front().second + 1);
            size_t const len = toVisit.size();
            for(size_t i = 0; i < len; i++){
                auto [curr, idx] = toVisit.front();
                toVisit.pop();
                if (curr->left) toVisit.emplace(curr->left, idx * 2);
                if (curr->right) toVisit.emplace(curr->right, idx * 2 + 1);
            }
        }
        return width;
    }
};
