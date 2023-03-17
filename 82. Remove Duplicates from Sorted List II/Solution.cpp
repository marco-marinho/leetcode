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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode solution_head;
        ListNode* solution_current = &solution_head;
        while (current){
            if ( (!previous && !current->next)
                || (!previous && current->next && current->next->val != current->val)
                || (!current->next && previous && previous->val != current->val)
                || (current && previous && previous->val != current->val && current->val != current->next->val))
            {
                solution_current->next = current;
                solution_current = current;
            }
            previous = current;
            current = current->next;
        }
        if (solution_current) solution_current->next = nullptr;
        return solution_head.next;
    }
};