class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        // Find the length and tail of the list
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        
        // Optimize k for rotations greater than list length
        k = k % len;
        if (k == 0) return head;
        
        // Find the new tail: (len - k - 1)th node from the start
        ListNode* newTail = head;
        for (int i = 0; i < len - k - 1; ++i) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        
        // Break the circle and connect the old tail to the old head
        newTail->next = nullptr;
        tail->next = head;
        
        return newHead;
    }
};