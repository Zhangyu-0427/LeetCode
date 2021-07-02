/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL)
        return l2;

    if(l2 == NULL)
        return l1;

    struct ListNode* cur1 = l1, *cur2 = l2, *newHead = NULL, *tail = NULL;
    if(cur1->val <= cur2->val)
    {
        newHead = tail = cur1;
        cur1 = cur1->next;
    }
    else
    {
        newHead = tail = cur2;
        cur2 = cur2->next;
    }

    //取小的尾插
    while(cur1 != NULL && cur2 != NULL)
    {
        if(cur1->val <= cur2->val)
        {
            tail->next = cur1;
            cur1 = cur1->next;
        }
        else
        {
            tail->next = cur2;
            cur2 = cur2->next;
        }
        tail = tail->next;
    }
    if(cur1 == NULL)
        tail->next = cur2;
    else
        tail->next = cur1;

        return newHead;
}
