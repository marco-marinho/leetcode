class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (auto w : words){
            if (!freq[w]) freq[w] = 1;
            else freq[w] += 1;
        }
        int maxfreq = 0;
        for (auto [w, f] : freq){
            maxfreq = max(f, maxfreq);
        }
        vector<string> output;
        while(output.size() < k){
            vector<string> temp;
            for (auto [w, f]: freq){
                if (f == maxfreq) temp.push_back(w);
            }
            sort(temp.begin(), temp.end());
            output.insert(output.end(), temp.begin(), temp.end());
            maxfreq--;
        }
        return vector<string>(output.begin(), output.begin() + k);
    }
};
