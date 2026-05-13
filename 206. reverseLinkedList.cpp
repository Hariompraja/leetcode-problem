// Dificulty easy
// https://leetcode.com/problems/reverse-linked-list


ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;

        while (cur != NULL) {

            ListNode* next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head = pre;
        return head;
    }