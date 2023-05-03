class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1;
        set<int> set2;

        for(const auto n: nums1){
            set1.insert(n);
        }
        for(const auto n: nums2){
            set2.insert(n);
        }

        vector<int> res1;
        vector<int> res2;

        set_difference(set1.begin(), set1.end(),
                       set2.begin(), set2.end(),
                       inserter(res1, res1.end()));

        set_difference(set2.begin(), set2.end(),
                set1.begin(), set1.end(),
                inserter(res2, res2.end()));

        return{res1, res2};
    }
};
