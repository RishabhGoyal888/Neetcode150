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

    int findSum(TreeNode* root, int &maxsum){
        if(!root) return 0;
        
        int left = max(findSum(root->left, maxsum),0);
        int right = max(findSum(root->right, maxsum),0);

        int currSum = root->val + left + right;
        maxsum = max(maxsum, currSum);
        
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        findSum(root, maxsum);
        return maxsum;
    }
};