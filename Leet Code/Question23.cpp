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
    // Function to add a node with a given value to the end of a linked list
    void addNode(ListNode* &current, int val) {
        current->next = new ListNode(val);
        current = current->next;
    }
    ListNode* merge(ListNode* a, ListNode* b) {
    ListNode* c = new ListNode(); // Dummy node for the merged list
    ListNode* currentC = c; // Pointer for traversing the merged list

    // Merge the lists until both 'a' and 'b' are non-empty
    while (a != nullptr && b != nullptr) {
        if (a->val < b->val) {
            currentC->next = a;
            a = a->next;
        } else {
            currentC->next = b;
            b = b->next;
        }
        currentC = currentC->next;


    }
    if (a != nullptr) {
        currentC->next = a;
    }

    if (b != nullptr) {
        currentC->next = b;
    }

    ListNode* mergedList = c->next;
    delete c; 

    return mergedList;
}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        ListNode* merged = nullptr; 

        for (ListNode* list : lists) {
            merged = merge(merged, list);
        }

        return merged; 
    }
};
