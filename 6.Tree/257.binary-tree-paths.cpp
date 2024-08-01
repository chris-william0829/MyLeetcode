/*

https://leetcode.cn/problems/binary-tree-paths/description/
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

    vector<string> result;
    vector<TreeNode*> path;

    void dfs(TreeNode* node){
        path.emplace_back(node);
        if(node->left == nullptr && node->right == nullptr){
            string temp = to_string(path[0]->val);
            for(int i=1;i<path.size();i++){
                temp = temp + "->" + to_string(path[i]->val);
            }
            result.emplace_back(temp);
            return;
        }
        if(node->left){
            dfs(node->left);
            path.pop_back();
        }
        if(node->right){
            dfs(node->right);
            path.pop_back();
        }
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root ==nullptr) return result;
        dfs(root);
        return result;
    }
};