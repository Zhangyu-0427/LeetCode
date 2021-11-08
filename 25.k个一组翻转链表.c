/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL) return NULL;
    struct ListNode* tmp = head;
    struct ListNode* new_head = NULL;
    int cnt = 0, k_ = k;
    while (tmp) {
        cnt++; tmp = tmp->next;
    }
    if (cnt == 1) return head;

    cnt /= k;
    struct ListNode* prev = NULL, * cur = head, * net = NULL;
    struct ListNode* prev_head, * prev_tail;
    struct ListNode* cur_head, * cur_tail;
    int j = 0;
    while (j < cnt) {

        int i = 0;
        while (i < k) {
            if (i == 0) cur_head = cur;
            if (i == k - 1) cur_tail = cur;
            net = cur->next;
            cur->next = prev;
            prev = cur;
            cur = net;
            i++;
        }
        // 确定新的头结点
        if (j == 0) {
            new_head = prev;
        }
        j++;
        prev = net = NULL;

        if (j >= 2) {
            prev_head->next = cur_tail;
        }
        prev_head = cur_head;
        prev_tail = cur_tail;

    }
    cur_head->next = cur;

    return new_head;
}