class Solution {
public:
    int maxArea(vector<int>& height) {
        auto max = 0;
        auto start = 0;
        auto end = height.size() - 1;
        while(start < end){
            auto current = height[start];
            auto other = height[end];
            auto min_height = current >= other ? other : current;
            auto area = min_height * (end - start);
            if (area > max){
                max = area;
            }
            if (current < other) start ++;
            else end--;
        }
        return max;
    }

};