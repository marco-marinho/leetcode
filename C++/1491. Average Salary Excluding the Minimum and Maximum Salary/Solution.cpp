class Solution {
public:
    double average(vector<int>& salary) {
        int min = salary[0];
        int max = salary[0];
        double sum = 0;
        for(auto value : salary){
            if (value > max){
                max = value;
            }
            else if( value < min){
                min = value;
            }
            sum += value;
        }
        return (double)(sum - min - max) / (double)(salary.size() - 2);
    }
};
