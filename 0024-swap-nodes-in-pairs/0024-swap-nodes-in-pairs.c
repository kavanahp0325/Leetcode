/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){
    if ((!head) || (!head->next))
        return head;
    
    struct ListNode* tmp = head;
    head = head->next;
    tmp->next = head->next;
    head->next = tmp;
    
    head->next->next = swapPairs(head->next->next);
    return head;
}