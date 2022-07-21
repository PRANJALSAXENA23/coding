234. Palindrome Linked List
Easy

9754

594

Add to List

Share
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9




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
//      ListNode* middle(ListNode* head ) {
//         ListNode* slow = head;
//         ListNode* fast = head -> next;
        
//         while(fast != NULL && fast-> next != NULL) {
//             fast = fast -> next -> next;
//             slow = slow -> next;
//         }
        
//         return slow;
//     }
    ListNode* middle(ListNode* head)
        
    {
        ListNode*temp=head;
        int count=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        int middle_node=count/2;
        ListNode* ans=head;
        while(middle_node--)
        {
            ans=ans->next;
        }
        
        return ans;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        ListNode* curr=head;
        
        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {

        if(head->next==NULL)
        {
            return true;
        }
        //find middle
        ListNode* m=middle(head);
        
        //reverse        
        ListNode* temp=m->next;
        m->next=reverse(temp);
        //comparing  
        ListNode* n1=head;
        ListNode* n2=m->next;
        while(n2!=NULL)
        {
            if(n1->val!=n2->val)
            {
                return false;
            }
            n1=n1->next;
            n2=n2->next;
        }
            //repeat reverse 
        temp=m->next;
        m->next=reverse(temp);
        return true;
    }
};
    
//         bool isPalindrome(ListNode* head) {
//      vector<int> a;
        
//         while(head!=NULL)

//         {
//             a.push_back(head->val);
//             head=head->next;
//         }
        
//         for(int i=0;i<a.size()/2;i++)
//         {
//             if(a[i]!=a[a.size()-i-1])
//             {
//                 return false;
//             }
            
//         }
//         return true;
//     }
        
        
// };