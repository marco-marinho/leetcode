class Solution {
public:
    string predictPartyVictory(const string &senate) {
        int cnt[2] = {0};
        queue<int> q;
        for (const auto &c : senate){
            if (c == 'R'){
                cnt[0]++;
                q.push(0);
            }
            if (c == 'D'){
                cnt[1]++;
                q.push(1);
            }
        }

        int toRemove[2] = {0};
        while(cnt[0] > 0 && cnt[1] > 0){
            auto curr = q.front();
            q.pop();
            if (toRemove[curr] > 0){
                cnt[curr]--;
                toRemove[curr]--;
            }
            else{
                toRemove[!curr]++;
                q.push(curr);
            }
        }

        if (cnt[1] > 0) return "Dire";
        return "Radiant";
    }
};
