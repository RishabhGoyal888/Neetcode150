class Solution {
public:
    void subfunc(vector<int>& nums, set<vector<int>> &ans, vector<int> &curr, int index, int size){
        if(index == size){
            sort(curr.begin(), curr.end());
            ans.insert(curr);
            return;
        }
        //calling left decision tree, not taking the current index element in the subset
        subfunc(nums, ans, curr, index + 1, size);  

        //calling right decision tree, taking the current index element in the subset
        curr.push_back(nums[index]); 
        subfunc(nums, ans, curr, index + 1, size);

        curr.pop_back(); //since passing the curr vector by refernce so popping back before return
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> ans;
        vector<int> curr;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        subfunc(nums, ans, curr, 0, n);

        for(auto x: ans){
            res.push_back(x);
        }
        return res;
    }
};