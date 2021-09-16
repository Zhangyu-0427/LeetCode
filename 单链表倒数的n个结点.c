/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //思路一 1.计算链表长度sz 2. 找到sz-n个结点并删除----很笨..
    int SList_len = 0;
    
    struct ListNode* cur = head;//记录当前结点
    struct ListNode* prev = head;//记录当前结点上一个结点
    //拷贝两份头指针的地址
    struct ListNode* tmp1_phead = head;
    struct ListNode* tmp2_phead = head;
    //记录单链表的长度
    while(tmp2_phead!= NULL)
    {
        tmp2_phead = tmp2_phead->next;
        SList_len++;
    }

    int flag = SList_len - n;
    //判断是否为头删
    if(flag == 0)
        return head->next;
    //常规情况：寻找倒数第n个结点
    while(flag--)
    {
        if(tmp1_phead)
        {
            cur = tmp1_phead->next;;
            prev = tmp1_phead;
            tmp1_phead = tmp1_phead->next;
        }
    }
    //此时cur即为倒数第n个结点
    if(cur->next == NULL)
    {   //cur为尾结点
        prev->next = NULL;
    }
    else
        //常规情况
        prev->next = cur->next;
    return head;
}