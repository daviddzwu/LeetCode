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
#include <queue>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int maxDepth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left != nullptr){
                    q.push(front->left);
                }
                if(front->right != nullptr){
                    q.push(front->right);
                }
            }
            maxDepth++;
        }
        return maxDepth;
    }
};