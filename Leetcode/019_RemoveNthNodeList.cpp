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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Define fast and slow pointers, fast pointer will have heads
        // up of 'n'
        ListNode* fast = head;
        ListNode* slow = head;
        
        // Move the fast pointer
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        // If fast pointer reaches the end of the list, we have to delete the head node
        if (fast == NULL) {
            ListNode* oldHead = head;
            head = head->next;
            delete oldHead;
            return head;
        }
        
        // Move forward both pointers till fast one reaches the tail node
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Delete the node after current location of slow pointer
        ListNode* nextNode = slow->next;
        slow->next = nextNode->next;
        delete nextNode;
        
        return head;
    }
};