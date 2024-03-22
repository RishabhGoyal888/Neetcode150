class Solution {
public:

    void csfunc(vector<int> &arr, int target, vector<int> &curr, vector<vector<int>> &res, int index, int len, int &sum){
        if(sum == target){
            res.push_back(curr);
            return;
        }
        if(index == len || sum > target){
            return;
        }
        sum += arr[index];
        curr.push_back(arr[index]);
        csfunc(arr,target,curr,res,index,len,sum);
        sum -= arr[index];
        curr.pop_back();

        csfunc(arr,target,curr,res,index + 1,len,sum);

        return;

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        int sum = 0;
        csfunc(candidates, target, curr, res, 0, candidates.size(), sum);
        return res;
    }
};