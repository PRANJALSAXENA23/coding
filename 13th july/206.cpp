206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []

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


void recursive(ListNode*&head,ListNode*curr,ListNode*prev)
{
    if(curr==NULL)   //base case 
    {
        head=prev;
        return;
    }
    
    ListNode*forward=curr->next;
    recursive(head,forward,curr);
    curr->next=prev;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        while(curr!=NULL)
        {
            
          forward=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=forward;
        }
        // recursive(head,curr,prev);
        //return head;   //recursive ke case mai;     
      return prev;
    }
};