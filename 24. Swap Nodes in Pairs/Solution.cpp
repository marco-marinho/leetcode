class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head;
        auto curr = head->next->next;
        auto [output, tail] = swapPair(head);
        while(curr){
            if(!curr->next){
                tail->next = curr;
                break;
            }
            auto nxtCurr = curr->next->next;
            auto [nHead, nTail] = swapPair(curr);
            tail->next = nHead;
            tail = nTail;
            curr = nxtCurr;
        }
        return output;
    }

    pair<ListNode*, ListNode*> swapPair(ListNode* head) {
        auto second = head->next;
        second->next = head;
        head->next = nullptr;
        return {second, head};
    }
};
