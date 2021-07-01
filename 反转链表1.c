/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;
    struct ListNode *newHead  = NULL, *cur = head, *next = head->next;
    while(cur)
    {
        //头插
        next = cur->next;
        cur->next = NULL;
        if(newHead == NULL)
            newHead = cur;
        else
        {
            cur->next = newHead;
            newHead = cur;
        }
        //迭代
        cur = next;
    }
    return newHead;
}
