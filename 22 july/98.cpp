98. Validate Binary Search Tree
Medium


Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-2^31 <= Node.val <= 2^31 - 1


class Solution {
    
public:
    /*
    void inorderTraversal(TreeNode*root,vector<int>&v){
        if(root==NULL)return;
        inorderTraversal(root->left,v);
        v.push_back(root->val);
        inorderTraversal(root->right,v);
    }
    
    bool solve(vector<int>&v){
        
        for(int i=0;i<v.size()-1;i++)
            if(v[i]>=v[i+1])return false;
        
        return true;
    }
    */
    bool solve(TreeNode*root,long long int left,long long int right){
        if(root==NULL)return true;
        if(root->val >left && root->val < right){
            bool leftAns = solve(root->left,left,root->val);
            bool rightAns = solve(root->right,root->val,right);
            return leftAns && rightAns;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        
        /*
        //Approach - 1
        // using vector T.C -> O(n)
        // Time Complexity :- O(n)
        //As we know inorder traversal of BST
        //gives sorted order.
        //we will check if array is sorted or not.
        
        vector<int>inorder;
        inorderTraversal(root,inorder);
        return solve(inorder);
        */
        
        
        //Approach 2 :- 
        //we are passing range i.e left and right range
        //and if our root->val is out of range we will return false;
        if(root==NULL)return false;
        if(root->left==NULL && root->right==NULL)return true;
        return solve(root,-2147483649,2147483649);
        
    }
};