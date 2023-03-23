class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output = {{}};
        for (auto i : nums){
            auto size = output.size();
            for (int j = 0; j < size; j++){
                auto buff = output[j];
                buff.push_back(i);
                output.push_back(buff);
            }
        }
        return output;
    }
};
