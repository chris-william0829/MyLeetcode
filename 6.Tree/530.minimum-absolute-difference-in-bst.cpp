/*

https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/
2024-8-6

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

    vector<int> inorder;
    void travel(TreeNode* root){
        if(root == nullptr) return;
        travel(root->left);
        inorder.push_back(root->val);
        travel(root->right);
        return;
    }

    int getMinimumDifference(TreeNode* root) {
        travel(root);
        int result = INT32_MAX;
        for(int i=1;i<inorder.size();i++){
            if(inorder[i] - inorder[i-1] < result){
                result = inorder[i] - inorder[i-1];
            }
        }
        return result;
    }
};