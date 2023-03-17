/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* turtle;
        ListNode* hare;
        if (head && head->next){
            turtle = head->next;
            hare = head->next->next;
        }
        else return nullptr;
        bool cycle_detected = false;
        while(turtle && hare){
            if (turtle == hare) {
                cycle_detected = true;
                break;
            }
            if (hare->next){
            turtle = turtle->next;
            hare = hare->next->next;
            }
            else break;
        }
        turtle = head;
        if (cycle_detected) {
            while(hare != turtle) {
                hare = hare->next;
                turtle = turtle->next;
            }
            return hare;
        }
        return nullptr;
    }
};
