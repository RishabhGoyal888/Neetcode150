class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> inc;
        deque<int> dec;
        int ans = 0;
        int i =0; int j=0;
        int count = 0;

        while(j < n){
            while(!inc.empty() && nums[inc.back()] >= nums[j]){
                inc.pop_back();
            }
            inc.push_back(j);

            while(!dec.empty() && nums[dec.back()] <= nums[j]){
                dec.pop_back();
            }
            dec.push_back(j);

            int dif = nums[dec.front()] - nums[inc.front()];
            if(dif > limit){
                i++;
                if(inc.front() < i) inc.pop_front();
                if(dec.front() < i) dec.pop_front();
            } else {
                ans = max(ans,j-i+1);
                j++;
            }

        }
        return ans;
    }
};