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
    int search(vector<int>& i, int &ins, int &ine, int val){
        for(int j = ins; j<=ine; j++){
            if(i[j] == val) return j;
        }
        return -1;
    }

    TreeNode* build(vector<int>& p, vector<int>& i, int &curr, int ins, int ine){
        if(ins> ine) return NULL;
        TreeNode* root = new TreeNode(p[curr]);
        int mid = search(i, ins, ine, p[curr]);
        curr++;
        root->left = build(p, i, curr, ins, mid - 1);
        root->right = build(p, i, curr, mid + 1, ine);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int curr = 0;
        int ins = 0;
        int ine = inorder.size() - 1;
        return build(preorder, inorder, curr, ins, ine);
    }
};