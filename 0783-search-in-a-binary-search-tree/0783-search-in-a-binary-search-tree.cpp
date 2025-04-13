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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        if(root->val == val) return root;

        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr->val == val){
                return curr;
            }
            else if(val < curr->val){
                curr = curr->left;
            }
            else if(val > curr->val){              
                curr = curr->right;
            }
        }
        return curr;
    }
};