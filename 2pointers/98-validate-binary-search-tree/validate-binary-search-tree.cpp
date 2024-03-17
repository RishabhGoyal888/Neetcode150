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
    bool checkTree(TreeNode* root, long mxleft, long mnright){
        if(!root) return true;
        if(root->val > mxleft && root->val < mnright) 
            return checkTree(root->left, mxleft, root->val) && checkTree(root->right, root->val, mnright);
        else return false;
    }
    
    bool isValidBST(TreeNode* root) {
        long mxleft = LONG_MIN;
        long mnright = LONG_MAX;
        bool flag = checkTree(root,mxleft, mnright);
        return flag;
    }
};