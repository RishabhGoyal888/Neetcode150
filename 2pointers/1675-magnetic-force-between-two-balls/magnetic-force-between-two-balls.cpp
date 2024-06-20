class Solution {
public:

    bool checkpossible(vector<int>& arr, int m, int n, int dist){
        int count = 1;
        int last = arr[0];
        for(int i =1;i<n;i++){
            if(arr[i] - last >=dist){
                count++;
                last = arr[i];
            }
            if(count >= m){
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& pos, int m) {
        int n = pos.size();
        sort(pos.begin(), pos.end());
        int low = 1; int high = pos[n-1]-pos[0];
        int ans = 1;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(checkpossible(pos,m,n,mid)){
                ans = mid;
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
        return ans;
    }
};