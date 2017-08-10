/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        ListNode* ptr = head;
        ListNode* res;
        ListNode* tail = head;
        int counter = 1;
        while(tail->next != NULL) {
            tail = tail->next;
            counter ++;
        }
        int kk = k % counter;
        if (kk == 0)
            return head;
        for (int i = 0; i < counter - kk - 1; i ++) {
            ptr = ptr->next;
        }
        res = ptr->next;
        tail->next = head;
        ptr->next = NULL;
        return res;
    }

};
