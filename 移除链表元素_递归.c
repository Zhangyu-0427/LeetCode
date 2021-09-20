struct ListNode* removeElements(struct ListNode* head, int val) {
    if (!head)
        return head;
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}