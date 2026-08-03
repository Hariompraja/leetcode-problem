/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* end)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != end)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode* Left = head;
        ListNode* Right = head;
        ListNode* prevLeft = nullptr;

        // Find the starting node of the reversing portion
        while (left - 1)
        {
            prevLeft = Left;
            Left = Left->next;

            left--;
            right--;
        }

        // Find the node just after the reversing portion
        Right = Left;

        while (right)
        {
            Right = Right->next;
            right--;
        }

        // Reverse and reconnect the left side
        if (prevLeft)
            prevLeft->next = reverseList(Left, Right);
        else
            head = reverseList(Left, Right);

        // Reconnect the right side
        Left->next = Right;

        return head;
    }
};