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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        int lengthListA = 0, lengthListB = 0;

        while(tempA)
        {
            tempA = tempA->next;
            lengthListA++;
        }

        while(tempB)
        {
            tempB = tempB->next;
            lengthListB++;
        }

        if(lengthListA >= lengthListB)
        {
            tempA = headA;
            tempB = headB;
        }
        else
        {
            tempA = headB;
            tempB = headA;
        }
        
        for(int i=0; i<abs(lengthListA - lengthListB); i++)
        {
            tempA = tempA->next;
        }
        
        while(tempA && tempB)
        {
            if(tempA == tempB)
            {
                return tempA;
            }

            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};
