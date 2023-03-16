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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int list_size = 0;
        ListNode* current = head;
        while(current != nullptr){
            current = current->next;
            list_size++;
        }
        if(n == list_size){
            return  head->next;
        }
        current = head;
        int to_remove = list_size - n;
        for(int i = 0; i < to_remove - 1; i++){
            current = current->next;
        }
        current->next = current->next->next;
        return head;
    }
};
