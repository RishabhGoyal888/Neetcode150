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
    void countF(TreeNode* root, int mx, int &count){
        if(!root) return;
        if(root->val >= mx) count++;


        mx=max(mx,root->val);
        countF(root->left, mx, count);
        countF(root->right, mx, count);
        return;
    }
    
    int goodNodes(TreeNode* root) {
        int ans = 0;
        countF(root, INT_MIN, ans);
        return ans;
    }
};