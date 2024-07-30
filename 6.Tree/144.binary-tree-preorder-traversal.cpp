/*

https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode*> preorder;
        preorder.push(root);
        while(!preorder.empty()){
            TreeNode* node = preorder.top();
            preorder.pop();
            result.emplace_back(node->val);
            if(node->right != nullptr){
                preorder.push(node->right);
            }
            if(node->left != nullptr){
                preorder.push(node->left);
            }
        }
        return result;
    }
};