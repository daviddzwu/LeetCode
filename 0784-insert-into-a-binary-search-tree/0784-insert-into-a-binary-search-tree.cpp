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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* insert = new TreeNode(val);
        if(root == nullptr){
            root = insert;
            return root;
        }
        if(root->val == val){
            return nullptr;
        }
        TreeNode* curr = root;

        while(curr != nullptr){
            if(val < curr->val){
                if(curr->left == nullptr){
                    curr->left = insert;
                    return root;
                }
                else{
                    curr = curr->left;
                }
            }
            else if(val > curr->val){
                if(curr->right == nullptr){
                    curr->right = insert;
                    return root;
                }
                else{
                    curr = curr->right;
                }
            }
        }
    return root;
    }
};