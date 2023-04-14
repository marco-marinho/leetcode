class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string ans = "0";
        for (int i = num2.size() - 1; i >= 0; i--){
            string temp = multiply(num1, num2[i] - '0');
            temp.insert(temp.size(), num2.size() - 1 - i, '0');
            ans = addStrings(ans, temp);
        }
        return ans;
    }

    string multiply(string s, int num){
        string output;
        int carry = 0;
        for (int i = s.size() - 1; i >= 0; i--){
            int res = num * (s[i] - '0') + carry;
            carry = res/10;
            output.insert(0, 1, (char)((res%10) + '0'));
        }
        if (carry){
            output.insert(0, 1, (char)(carry + '0'));
        }
        return output;
    }

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
