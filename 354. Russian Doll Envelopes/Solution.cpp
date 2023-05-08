class Solution {
public:

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto comparelamb = [](const vector<int> &a, const vector<int> &b){
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };
        sort(envelopes.begin(), envelopes.end(), comparelamb);
        vector<int> res;

        for (const auto &element: envelopes){
            int width = element[1];
            auto it =  lower_bound(res.begin(), res.end(), width);
            if(it == res.end()) res.emplace_back(width);
            else *it = width;
        }

        return res.size();
    }
};
