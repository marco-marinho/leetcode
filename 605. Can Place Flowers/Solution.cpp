class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++){
            bool prev = i - 1 < 0 || !flowerbed[i - 1];
            bool next = i + 1 >= flowerbed.size() || !flowerbed[i + 1];
            if (prev && next && !flowerbed[i]) {
                flowerbed[i] = 1;
                count++;
            }
        }
        return count >= n;
    }
};