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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* result = NULL;
        ListNode* tail = NULL;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            if (result == NULL) {
                result = new ListNode(sum % 10);
                tail = result;
            }
            else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            int sum = l1->val + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int sum = l2->val + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            l2 = l2->next;
        }
        if (carry != 0) {
            tail->next = new ListNode(carry);
            tail = tail->next;
        }
        return result;
    }
};