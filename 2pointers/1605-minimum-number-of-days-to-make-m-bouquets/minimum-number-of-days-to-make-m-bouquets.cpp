class Solution {
public:

    bool valid(vector<int>& bloomDay, int m, int k, int day){
        int total = 0;
        for(int i=0;i<bloomDay.size();i++){
            int count = 0;

            while(i<bloomDay.size() && count<k && bloomDay[i] <=day ){
                count++;
                i++;
            }
            if(count == k){
                total++;
                i--;
            }
            if(total == m){
                return true;
            }
        }
            return false;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k > n) return -1;

        int low = 1;
        int high = INT_MAX;

        while(low < high){
            int mid = low + (high-low)/2;
            
            if(valid(bloomDay, m, k, mid))
                high = mid;
            else
                low = mid + 1;
        } 
        return low;
    }
};