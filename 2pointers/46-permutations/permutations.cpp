class Solution {
public:
    void swapf(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
        return;
    }

    void permutesubfunc(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int start){
        if(start == nums.size()-1){
            ans.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++){
            swap(nums[start], nums[i]);
            permutesubfunc(nums, ans, curr, start+1);
            swap(nums[start], nums[i]);
        }
        return;

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        permutesubfunc(nums, ans, curr, 0);
        return ans;
    }
};