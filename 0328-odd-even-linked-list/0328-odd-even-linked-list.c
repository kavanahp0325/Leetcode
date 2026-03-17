/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if (!head || !head->next || !head->next->next)
        return head;

    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* evenHead = head->next;

    while (even && even->next) {
        odd->next = even->next;
        odd = even->next;
        even->next = odd->next;
        even = odd->next;
    }
    odd->next = evenHead;
    return head;
}
  