21. Merge Two Sorted Lists
Easy

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.


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
    
    ListNode* solve(ListNode*list1,ListNode* list2)
    {
        if(list1->next==NULL)
            
        {
            list1->next=list2;
            return list1;
        }
        ListNode* curr1=list1;
           ListNode* forward1=curr1->next;
           ListNode* curr2=list2;
           ListNode* forward2=curr2->next;
        
        
        while(forward1!=NULL&&curr2!=NULL)
        {
            if(curr2->val>=curr1->val&&(curr2->val<=forward1->val))
            {
                curr1->next=curr2;
                forward2=curr2->next;
                curr2->next=forward1;
                
                curr1=curr2;
                curr2=forward2;
            }
            else
            {
                curr1=forward1;
                forward1=forward1->next;
                
                
                if(forward1==NULL)
                {
                    curr1->next=curr2;
                    return list1;
                }
            }
        }
        return list1;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        ListNode * ans=new ListNode();
        if(list1->val<=list2->val)
        {
           ans= solve(list1,list2);
        }
        else
        {
            ans=solve(list2,list1);
        }
        return ans;
    }
};