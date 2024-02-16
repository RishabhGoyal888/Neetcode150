class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int start=0;
        int end=n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            int low = arr[(mid + n- 1)%n];
            int high = arr[(mid + 1)%n];
            if(arr[mid] <= low && arr[mid] <= high){
                return arr[mid];
            }

            else if(arr[mid] <= arr[end]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }
};