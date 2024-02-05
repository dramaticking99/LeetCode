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
     ListNode* removeNthFromEnd(ListNode* head, int n) {
         if(head->next == NULL){
             head = NULL;
             return head;
         }

         ListNode* dummyHead = head;
         ListNode* dNode = head;
         ListNode* node;

         int d = 0;
         int h = 0;

         ListNode* current = head;
         while(current->next != NULL){
             current = dummyHead->next;
             dummyHead = current;
             h++;
            if( h-d >= n ) {
                node = dNode;
                dNode = dNode->next;
                d++;
            }
         }

         if(dNode == head){
             head = head->next;
         } else {
             node->next = dNode->next;
         }

         return head;
     }
};
