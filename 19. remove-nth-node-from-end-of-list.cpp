// Difficulty Medium
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

 ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;

        ListNode* temp = head;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }

        if(n == size){
            ListNode* delHead = head;
            head = head->next;
            delete delHead;
            return head;

        }
        ListNode* pre = head;
        for (int i = 1; i < size - n; i++) {
            pre = pre->next;
        }
        ListNode* delNode = pre->next;
        pre->next = pre->next->next;
        delete delNode;
        

        return head;
    }