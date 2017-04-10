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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL && l2 != NULL) return l2;
        if (l1 != NULL && l2 == NULL) return l1;
        
        ListNode* result = NULL;
        ListNode* resultTail = NULL;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                ListNode* newNode = new ListNode(l1->val);
                l1 = l1->next;
                if (result == NULL) {
                    result = newNode;
                    resultTail = newNode;
                }
                else {
                    resultTail->next = newNode;
                    resultTail = resultTail->next;
                }
            }
            else {
                ListNode* newNode = new ListNode(l2->val);
                l2 = l2->next;
                if (result == NULL) {
                    result = newNode;
                    resultTail = newNode;
                }
                else {
                    resultTail->next = newNode;
                    resultTail = resultTail->next;
                }
            }
        }
        while (l1 != NULL) {
            ListNode* newNode = new ListNode(l1->val);
            l1 = l1->next;
            resultTail->next = newNode;
            resultTail = resultTail->next;
        }
        while (l2 != NULL) {
            ListNode* newNode = new ListNode(l2->val);
            l2 = l2->next;
            resultTail->next = newNode;
            resultTail = resultTail->next;
        }
        return result;
    }
};