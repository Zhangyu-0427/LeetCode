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

    struct ListNode* n1 = NULL, *n2 = head, *n3 = head->next;
    while(n2 != NULL)
    {
        //反转
        n2->next = n1;

        //迭代
        n1 = n2;
        n2 = n3;
        if(n3 != NULL)
            n3 = n3->next;
    }

    return n1;
}
