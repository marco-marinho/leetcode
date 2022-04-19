/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1val = 0;
        int l2val = 0;
        int carry = 0;
        auto *output = new ListNode();
        ListNode* buffer = output;
        while(l1 != nullptr || l2 != nullptr){
                l1val = l1 != nullptr ? l1->val : 0;
                l1 = l1 != nullptr ? l1->next : nullptr;
                l2val = l2 != nullptr ? l2->val : 0;
                l2 = l2 != nullptr ? l2->next : nullptr;
                buffer->val = (l1val + l2val + carry) % 10;
                carry = (l1val + l2val + carry) / 10 > 0 ? 1 : 0;
                auto* next = l1 != nullptr || l2 != nullptr ? new ListNode() : carry > 0 ? new ListNode(1) : nullptr;
                buffer->next = next;
                buffer = next;
        }
        return output;
    }
};
