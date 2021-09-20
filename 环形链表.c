bool hasCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return false;
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = (fast->next)->next;
        if (fast == NULL)
            return false;
        if (slow == fast->next)
            break;
    }
    return slow == fast->next ? true : false;
}