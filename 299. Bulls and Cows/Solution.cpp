class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> leftSecret;
        unordered_map<char, int> leftGuess;
        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) bulls++;
            else{
                if (!leftSecret[secret[i]]) leftSecret[secret[i]] = 1;
                else leftSecret[secret[i]] += 1;
                if (!leftGuess[guess[i]]) leftGuess[guess[i]] = 1;
                else leftGuess[guess[i]] += 1;
            }
        }
        for (auto [c, n] : leftGuess){
            if (!leftSecret[c]) continue;
            cows += min(leftSecret[c], n);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
