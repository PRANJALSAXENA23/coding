110. Balanced Binary Tree
Easy


Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(root==NULL)
            
        {
            return 0;
        }
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        
        return max(l,r)+1;
        
    }
    bool isBalanced(TreeNode* root) {
        
        if(root==NULL)
        {
            return true;
            
        }
        
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
         bool ans=abs(maxDepth(root->left)-maxDepth(root->right))<=1;
        
        if(left&&right&&ans)
            
        {
            return true;
        }
        return false;
        
    }
};