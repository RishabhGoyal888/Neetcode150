#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int helpfx(vector<int>& nums, int k){
        if(k<0) return 0;
        int count = 0;
        int ans = 0;
        int i =0;
        int j =0;
        while(j<nums.size()){
            if(nums[j] % 2 == 1){
                count++;
            }
            while(count>k){
                if(nums[i] % 2 ==1){
                    count--;
                }
                    i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return helpfx(nums,k) - helpfx(nums, k-1);
    }
}; 
