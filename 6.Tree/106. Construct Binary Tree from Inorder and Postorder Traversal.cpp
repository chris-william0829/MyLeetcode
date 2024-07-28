/*

https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
2024-7-28

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0){
            return nullptr;
        }
        int root = postorder[postorder.size()-1];
        int index = 0;
        for(; index < inorder.size(); index++){
            if(inorder[index] == root){
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(),inorder.begin()+index);
        vector<int> rightInorder(inorder.begin()+index+1,inorder.end());
        postorder.pop_back();
        vector<int> leftPostorder(postorder.begin(),postorder.begin()+leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());
        TreeNode* node = new TreeNode(root);
        node->left = buildTree(leftInorder, leftPostorder);
        node->right = buildTree(rightInorder, rightPostorder);
        return node;
    }
};