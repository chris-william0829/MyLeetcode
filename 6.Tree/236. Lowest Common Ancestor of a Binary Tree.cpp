/*

https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
2024-7-27

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool dfs(TreeNode* root, TreeNode* target, vector<TreeNode*> &path){
        if(root == target){
            path.emplace_back(root);
            return true;
        }
        path.emplace_back(root);
        if(root->left != nullptr){
            if(dfs(root->left,target,path)){
                return true;
            }else{
                path.pop_back();
            }
        }
        if (root->right != NULL){
            if(dfs(root->right,target,path)){
                return true;
            }else{
                path.pop_back();
            }
        }
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        dfs(root,p,path1);
        dfs(root,q,path2);
        for(int i=path1.size()-1;i>=0;i--){
            for(int j=path2.size()-1;j>=0;j--){
                if(path1[i] == path2[j]){
                    return path1[i];
                }
            }
        }
        return nullptr;       
    }
};


/*
递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || !root) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p ,q);
        TreeNode *right = lowestCommonAncestor(root->right, p ,q);
        if(left && right) return root;
        if(!left) return right;
        return left;
    }
};
*/