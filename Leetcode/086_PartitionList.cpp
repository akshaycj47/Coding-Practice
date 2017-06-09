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
    ListNode* partition(ListNode* head, int x) {
        
        // Base condition 
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        // Find the first node which is greater or equal to target
        ListNode* leftNode = NULL;
        ListNode* rightNode = NULL;
        
        // There can be two conditions, one where head is the first greater or equal to target,
        // and one where some mid element is the first greater or equal to target
        if(head->val >= x) {
            leftNode = NULL;
            rightNode = head;
        }
        else {
            ListNode* curr = head;
            while(curr->next != NULL) {
                ListNode* nextNode = curr->next;
                if(nextNode->val >= x) {
                    leftNode = curr;
                    rightNode = nextNode;
                    break;
                }
                curr = nextNode;
            }
        }
        
        // If no greater or equal to target element found, return the list as is
        if( leftNode == NULL && rightNode == NULL )
        {
            return head;
        }
        
        ListNode* temp = rightNode;
        while(temp->next != NULL) {
            ListNode* nextNode = temp->next;
            
            // If this element is less than target, we need to remove it,
            // and add it between left and right nodes that we found earlier
            if(nextNode->val < x) {
                ListNode* toInsert = nextNode;
                temp->next = nextNode->next;
                
                // If left node is null, it means we have to insert element at the head
                if(leftNode == NULL) {
                    toInsert->next = head;
                    head = toInsert;
                }
                else {
                    leftNode->next = toInsert;
                    toInsert->next = rightNode;
                }
                
                // Inserted node will now become the left node
                leftNode = toInsert;
            }
            
            // If element is not less than target, then we need to move ahead
            else {
                temp = nextNode;
            }
        }
        
        return head;
    }
};
