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

    void dfsTree(TreeNode* node, unordered_map<TreeNode*, vector<TreeNode*>> &mp, vector<TreeNode*> &leaves, vector<TreeNode*> &path){
        if(!node) return;
        path.push_back(node);
        if(!node->left && !node->right){
            leaves.push_back(node);
            mp[node] = path;
        }
        dfsTree(node->left, mp,leaves, path);
        dfsTree(node->right, mp,leaves, path);
        path.pop_back();
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> mp;
        vector<TreeNode*> leaves;
        vector<TreeNode*> path;
        dfsTree(root,mp,leaves,path);
        int ans = 0;
        for(auto x: mp){
            cout<<x.first->val;
            for(auto y :x.second){
                cout<<y->val;
            }
            cout<<"  ";
        }
        for(int i=0;i<leaves.size();i++){
            for(int j=i+1;j<leaves.size();j++){
                vector<TreeNode*> first = mp[leaves[i]];
                vector<TreeNode*> second = mp[leaves[j]];
                for(int k=0;k<min(first.size(),second.size());k++){
                    if(first[k] != second[k]){
                        int dist = first.size() - k + second.size() - k;
                        if( dist<= distance) {
                            ans++;
                        }
                        break;
                    }
                }
            }
        }
        return ans;

    }
};