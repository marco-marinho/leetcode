class Compare {
public:
    bool operator()(pair<int, int> first, pair<int, int> second)
    {
        return first.first > second.first;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (!lists[i]) continue;
            pq.emplace(lists[i]->val, i);
        }
        if (pq.empty()) return nullptr;
        auto first = pq.top().second;
        pq.pop();
        ListNode *head = lists[first];
        ListNode *curr = head;
        lists[first] = lists[first]->next;
        if (lists[first]) pq.emplace(lists[first]->val, first);
        while (!pq.empty()) {
            auto j = pq.top().second;
            pq.pop();
            curr->next = lists[j];
            curr = curr->next;
            lists[j] = lists[j]->next;
            if (lists[j]) pq.emplace(lists[j]->val, j);
        }
        return head;
    }
};
