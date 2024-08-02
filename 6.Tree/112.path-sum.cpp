/*

https://leetcode.cn/problems/path-sum/description/
2024-8-2

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

    bool dfs(TreeNode* root, int targetSum, int sum){
        sum += root->val;
        if(root->left == nullptr && root->right == nullptr){
            if(sum == targetSum){
                return true;
            }else{
                return false;
            }
        }
        bool l, r;
        if(root->left) l = dfs(root->left, targetSum, sum);
        if(root->right) r = dfs(root->right, targetSum, sum);
        return l||r;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return dfs(root,targetSum,0);
    }
};