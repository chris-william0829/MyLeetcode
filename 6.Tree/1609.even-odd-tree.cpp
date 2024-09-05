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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int num = 0;
        while(!q.empty()){
            int n = q.size();
            int pre;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if((num % 2 + node->val % 2) != 1){
                    return false;
                }
                if(i == 0){
                    pre = node->val;
                }else{
                    if(num % 2 == 0 && node->val <= pre){
                        return false;
                    }else if(num % 2 == 1 && node->val >= pre){
                        return false;
                    }
                    pre = node->val;
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            num++;
        }
        return true;
    }
};