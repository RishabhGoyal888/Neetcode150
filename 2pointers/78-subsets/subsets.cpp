class Solution {
public:

    void subfunc(vector<int>& nums, vector<vector<int>> & ans, vector<int> &curr, int index, int size){
        if(index == size){
            ans.push_back(curr);
            return;
        }
        subfunc(nums, ans, curr, index + 1, size);

        curr.push_back(nums[index]);
        subfunc(nums, ans, curr, index + 1, size);
        curr.pop_back();
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = nums.size();
        subfunc(nums, ans, curr, 0, n);
        return ans;
    }
};