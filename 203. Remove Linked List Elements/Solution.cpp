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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* nhead = head;
        while(nhead && nhead->val == val) nhead = nhead->next;
        ListNode* current = nhead;
        ListNode* prev = nullptr;
        while(current){
            if (current && current->val == val){
                if (prev) {
                    prev->next = current->next;
                    current = current->next;
                }
            }
            else {
                prev = current; 
                current = current->next;
            }
        }
        return nhead;
    }
};
