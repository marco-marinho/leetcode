class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        int p1 = m-1;
        int p2 = n-1;
        int p_ins = m + n - 1;
        while(p1 >= 0 && p2 >= 0){
            if (nums2[p2] >= nums1[p1]){
                nums1[p_ins] = nums2[p2];
                p2--;
                p_ins--;
            }
            else {
                nums1[p_ins] = nums1[p1];
                p1--;
                p_ins--;
            }
        }
        while (p2 >= 0) {
                nums1[p_ins] = nums2[p2];
                p2--;
                p_ins--;
        }
    }
};
