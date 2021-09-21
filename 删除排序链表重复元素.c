struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    //以下情况链表元素至少为两个
    struct ListNode* slow = head, * fast = head->next;
    while (fast)
    {
        if (slow->val == fast->val)
        {
            slow->next = fast->next;
            fast = fast->next;
        }
        else
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return head;
}