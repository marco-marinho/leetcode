class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> nums;
        for(int i = 0; i < nums2.size(); i++){
            int val = nums2[i];
            while(!nums.empty() && nums.top() < val){
                nextGreater[nums.top()] = val;
                nums.pop();
            }
            nums.push(val);
        }
        vector<int> output(nums1.size(), 0);
        for (int i = 0; i < nums1.size(); i++){
            if (nextGreater.find(nums1[i]) == nextGreater.end()) output[i] = -1;
            else output[i] = nextGreater[nums1[i]];
        }
        return output;
    }

};
