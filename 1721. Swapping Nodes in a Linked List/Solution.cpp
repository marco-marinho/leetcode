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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* current = head;
        int pos = 1;
        for(int i = 1; i < k; i++){
            current = current->next;
        }
        ListNode* first = current;
        ListNode* second = head;
        while(current->next){
            current = current->next;
            second = second->next;
        }
        swap(first->val, second->val);
        return head;
    }
};
