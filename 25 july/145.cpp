145.postorder

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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> result;
        stack <TreeNode *> st1;
        stack <int> st2;
        if(root==NULL)
            return result;
        else
            st1.push(root);
        while(!st1.empty())
        {
            auto temp = st1.top();
            st1.pop();
            if(temp->left)
                st1.push(temp->left);
            if(temp->right)
                st1.push(temp->right);
            st2.push(temp->val);
        }
        while(!st2.empty())
        {
            result.emplace_back(st2.top());
            st2.pop();
        }
        return result;
    }
};
//Recursive:

// class Solution {
// public:
//     void postorder(TreeNode* root,vector <int> &result)
//     {
//         if(root==NULL)
//             return;
//         postorder(root->left,result);
//         postorder(root->right,result);
//         result.emplace_back(root->val);
            
            
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> result;
//         postorder(root,result);
//         return result;
//     }
// };