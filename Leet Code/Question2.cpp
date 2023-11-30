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
class Solution
{

private:
    struct ListNode *createNode(int val)
    {
        struct ListNode *newNode = new ListNode;
        newNode->val = val;
        newNode->next = nullptr;

        return newNode;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        struct ListNode *l3 = nullptr;
        struct ListNode *current;
        int numLeft = 0;

        while (l1 != nullptr && l2 != nullptr)
        {

            int num3 = l1->val + l2->val + numLeft;
            int val = num3 % 10;
            numLeft = num3 / 10;

            struct ListNode *newNode = createNode(val);

            if (l3 == nullptr)
            {
                // If the list is empty, set the new node as head
                l3 = newNode;
                current = l3;
            }
            else
            {
                current->next = newNode;
                current = newNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 != nullptr)
        {

            while (l1 != nullptr)
            {

                int num = l1->val + numLeft;
                int digit = num % 10;
                numLeft = num / 10;

                struct ListNode *newNode = createNode(digit);

                if (l3 == nullptr)
                {
                    // If the list is empty, set the new node as head
                    l3 = newNode;
                    current = l3;
                }
                else
                {
                    current->next = newNode;
                    current = newNode;
                }
                l1 = l1->next;
            }
        }
        if (l2 != nullptr)
        {
            while (l2 != nullptr)
            {

                int num = l2->val + numLeft;
                int digit = num % 10;
                numLeft = num / 10;

                struct ListNode *newNode = createNode(digit);

                if (l3 == nullptr)
                {
                    // If the list is empty, set the new node as head
                    l3 = newNode;
                    current = l3;
                }
                else
                {
                    current->next = newNode;
                    current = newNode;
                }
                l2 = l2->next;
            }
        }

        if(numLeft != 0){
            struct ListNode *newNode = createNode(numLeft);
            current->next = newNode;
                    current = newNode;
        }

        return l3;
    }
};
