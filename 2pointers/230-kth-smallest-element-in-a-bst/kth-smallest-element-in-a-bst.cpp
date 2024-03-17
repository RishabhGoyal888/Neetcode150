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
    void func(TreeNode* root, int &k, int &ans){
        if(!root) return;

        func(root->left, k, ans);
        k--;
        if(k == 0) ans = root->val;
        func(root->right, k, ans);

        return ;
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        func(root, k, ans);
        return ans;
    }
};