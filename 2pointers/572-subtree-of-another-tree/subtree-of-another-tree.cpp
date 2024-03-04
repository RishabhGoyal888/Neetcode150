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
    bool checksame(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot)
            return true;
        else if(!root || !subRoot)
            return false;
        else if(root->val != subRoot->val)
            return false;
        return checksame(root->left, subRoot->left) && checksame(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        bool ans = false;
        ans = checksame(root, subRoot);
        if(ans) return ans;
        ans= isSubtree(root->left,subRoot);
        if(ans) return ans;
        ans= isSubtree(root->right,subRoot);
        if(ans) return ans;

        return ans;

    }
};