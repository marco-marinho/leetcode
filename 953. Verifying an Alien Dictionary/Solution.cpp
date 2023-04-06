class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int numOrd[26] = {0};
        for (int i = 0; i < order.size(); i++){
            numOrd[order[i] - 'a'] = i;
        }
        for (int i = 0; i < words.size() - 1; i++){
            if (!areOrdered(words[i], words[i + 1], numOrd)) return false;
        }
        return true;
    }

    bool areOrdered(string &first, string &second, int* numOrd){
        int p = 0;
        while(p < first.size() && p < second.size()){
            int iFirst = first[p] - 'a';
            int iSecond = second[p] - 'a';
            if (numOrd[iFirst] > numOrd[iSecond]) return false;
            else if (numOrd[iFirst] < numOrd[iSecond]) return true;
            p++;
        }
        if (second.size() < first.size()) return false;
        return true;
    }

};
