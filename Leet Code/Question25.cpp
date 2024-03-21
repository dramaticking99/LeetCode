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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) 
            return head;

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* current = dummy;
        
        while (current->next != nullptr) {
            ListNode* start = current->next;
            ListNode* end = current->next;

            for (int i = 1; i < k && end != nullptr; ++i)
                end = end->next;

            if (end == nullptr) 
                break;

            ListNode* nextGroup = end->next;
            end->next = nullptr; 
            
            // Reverse the current group
            ListNode* reversedStart = reverse(start);
        
            current->next = reversedStart;
            start->next = nextGroup;
            
            current = start;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
