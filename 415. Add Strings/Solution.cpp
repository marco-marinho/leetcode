class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size() - 1;
        int m = num2.size() - 1;
        string output;
        int carry = 0;
        int offset = 0;
        while(n - offset >= 0 || m - offset >= 0){
            char cur1 = n - offset >= 0 ? num1[n - offset] : '0';
            char cur2 = m - offset >= 0 ? num2[m - offset] : '0';
            int sum = (cur1 - '0') + (cur2 - '0') + carry;
            char sumC = '0' + (sum%10);
            carry = sum / 10;
            output.insert(0, 1, sumC);
            offset++;
        }
        if (carry) output.insert(0, 1, '1');
        return output;
    }
};
