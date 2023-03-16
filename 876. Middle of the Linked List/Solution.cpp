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
    ListNode* middleNode(ListNode* head) {
        int list_size = 0;
        ListNode* current = head;
        while(current != nullptr){
            current = current->next;
            list_size++;
        }
        current = head;
        int middle = (list_size / 2);
        for(auto i = 0; i < middle; i++){
            current = current->next;
        }
        return current;
    }
};
