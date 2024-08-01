/*

https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/
2024-8-1

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
    vector<int> result;
    int maxCount;
    int count;
    int val;
    void dfs(TreeNode *root){
        if(root == nullptr) return;
        dfs(root->left);
        if(root->val == val){
            count++;
        }else{
            val = root->val;
            count = 1;
        }
        if(count == maxCount){
            result.push_back(val);
        }
        if(count > maxCount){
            maxCount = count;
            result = vector<int>{val};
        }
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return result;
    }
};