/*

https://leetcode.cn/problems/find-bottom-left-tree-value/description/
2024-8-5

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        int result = root->val;
        while(!q1.empty()){
            result = q1.front()->val;
            while(!q1.empty()){
                TreeNode* node = q1.front();
                q1.pop();
                if(node->left != nullptr) q2.push(node->left);
                if(node->right != nullptr) q2.push(node->right);
            }
            swap(q1,q2);
        }
        return result;
    }
};