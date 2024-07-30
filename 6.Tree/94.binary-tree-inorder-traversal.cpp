/*

https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
2024-7-30

*/


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode*> inorder;
        TreeNode* cur = root;
        while(!inorder.empty() || cur != nullptr){
           if(cur != nullptr){
               inorder.push(cur);
               cur=cur->left;
           }else{
                cur = inorder.top();
                inorder.pop();
                result.push_back(cur->val);     // 中
                cur = cur->right;
           }
        }
        return result;
    }
};