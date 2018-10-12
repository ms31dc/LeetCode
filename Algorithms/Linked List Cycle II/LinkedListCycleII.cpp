/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *turtle = head, *rabbit = head;
        while(turtle && rabbit && rabbit->next)
        {
            turtle = turtle->next;
            rabbit = rabbit->next->next;
            if(rabbit == turtle)
            {
                ListNode *snail = head;
                while(rabbit != snail)
                {
                    snail = snail->next;
                    rabbit = rabbit->next;
                }
                return rabbit;
            }
        }
        return NULL;
    }
};
