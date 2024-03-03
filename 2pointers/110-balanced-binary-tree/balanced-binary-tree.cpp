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
    int heightoftree(TreeNode* root, bool &isBalance){
        if(!root) return 0;

        int lh = heightoftree(root->left, isBalance);
        int rh = heightoftree(root->right, isBalance);

        if(abs(lh-rh) > 1) isBalance = false;

        return 1 + max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        bool isBalance = true;
        int h = heightoftree(root, isBalance);
        return isBalance;
    }
};