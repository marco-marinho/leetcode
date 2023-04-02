class Solution {
public:
    vector<int> successfulPairs(vector<int> spells, vector<int> potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (auto s: spells){
            int idx = findFirst(s, potions, success);
            res.emplace_back(potions.size() - idx);
        }
        return res;
    }

    int findFirst(int spell, vector<int>& potions, long long sucess){
        int left = 0;
        int right = potions.size() - 1;
        int half = 0;
        while(left <= right){
            half = (right + left) / 2;
            long long temp = (long long)potions[half] * spell;
            if (temp >= sucess) right = half - 1;
            else left = half + 1;
        }
        return left;
    }

};
