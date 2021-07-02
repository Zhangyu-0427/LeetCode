/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if(head == NULL)
        return head;
    if(head->next == NULL && head->val != val)
        return head;
    if(head->next == NULL && head->val == val)
        return NULL;

    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* newHead = head;
    int flag = 1;
    while(cur)
    {
        flag  = 1;
        if(cur->val == val)
        {
            if(cur == newHead)
                newHead = cur->next;
            else
            {
                prev->next = cur->next;
                flag = 0;
            }
        }
        if(flag)
            prev = cur;
        cur = cur->next;
    }

    return newHead;
}
