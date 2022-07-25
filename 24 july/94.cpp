93. INORDER




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
    vector<int> inorderTraversal(TreeNode* p) {
        vector<int> ans;
         stack<TreeNode*> stk;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.emplace(p);
            p = p->left;
        } else {
            p = stk.top();
            stk.pop();
           ans.push_back(p->val);
            p = p->right;
        }
    }
        return ans;
    }
    
    //recursive
//        void inorder(TreeNode *root, vector<int>&ans)
//     {
//       if(root){
//           inorder(root->left, ans);
//           ans.push_back(root->val);
//           inorder(root->right, ans);
//       }
       
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         inorder(root,ans);
//         return ans;
//     }
};