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
    TreeNode* deleteNode(TreeNode*& root, int key) {
        if(root == nullptr){
            return nullptr;
        }
        TreeNode* parent = nullptr;
        TreeNode* curr = root;
        bool isLeft = false;

        while(curr != nullptr){
            if(curr->val == key){
                break;
            }
            if(key < curr->val){
                parent = curr;
                curr = curr->left;
                isLeft = true;
            }
            else{
                parent = curr;
                curr = curr->right;
                isLeft = false;
            }
        }
        if(curr == nullptr){
            return root;
        }

        if(curr->left == nullptr && curr->right == nullptr){
            if(parent == nullptr){
                delete root;
                root = nullptr;
                return nullptr; 
            }
            else if(isLeft){
                parent->left = nullptr;
                delete curr;
                return root;
            }
            else{
                parent->right = nullptr;
                delete curr;
                return root;
            }
        }
        else if(curr->left != nullptr && curr->right == nullptr){
            if(parent == nullptr){
                root = curr->left;
                delete curr;
                return root;
            }
            else if(isLeft){
                parent->left = curr->left;
                delete curr;
                return root;
            }
            else{
                parent->right = curr->left;
                delete curr;
                return root;
            }
            if(parent == nullptr){
                root = curr->right;
                delete curr;
                return root;
            }
            else if(isLeft){
                parent->left = curr->right;
                delete curr;
                return root;
            }
            else{
                parent->right = curr->right;
                delete curr;
                return root;
            }
        }

        else{
            TreeNode* sP = curr;
            TreeNode* s = curr->right;

            while(s->left != nullptr){
                sP = s;
                s = s->left;
            }
            curr->val = s->val;

            if(sP->left == s){
                sP->left = s->right;
            }
            else{
                sP->right = s->right;
            }
            delete s;
        }
    return root;
    }
};