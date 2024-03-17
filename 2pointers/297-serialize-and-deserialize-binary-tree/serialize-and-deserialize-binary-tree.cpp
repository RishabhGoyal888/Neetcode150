/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void helper(TreeNode* root, string &s){
        if(!root){
            s += "N|";
            return;
        } 
        s=s + to_string(root->val) + "|";
        helper(root->left, s);
        helper(root->right, s);
        return;

    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        helper(root,s);
        for(auto x: s){
            cout<<x;
        }
        return s;
    }

    TreeNode* helper2(string &data, int &curr){

        if(data[curr] == 'N'){
            curr++;
            curr++;
            return NULL;
        }
        int sign = 1;
        if (data[curr] == '-') {
            sign = -1;
            curr++; // Skip the negative sign
        }
        int value=0;
        while(data[curr] != '|'){
            value = value * 10 + (data[curr] - '0');
            curr++;
        }
        // string temp = "";
        // while(data[curr] != '|'){
        //     temp += data[curr++];
        // }
        TreeNode* root = new TreeNode(value * sign);
        curr++;
        root->left = helper2(data, curr);
        root->right = helper2(data, curr);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int curr=0;
        TreeNode* root = helper2(data,curr);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));