class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] == target)
                return mid;
        //checking which side is sorted, jaunsi side sorted ho usme hi compare kr skte hai ki ussme hai ya nhi.
            else if(arr[mid] <= arr[end]){  //agr right sorted hai to usme compare krenge
                if(target >= arr[mid] && target <= arr[end]){
                    start = mid+1;
                }
                else end = mid-1;
            }
            else if(arr[start] <= arr[mid]){ //agr left sorted hai to usme compare krenge
                if(target >= arr[start] && target <= arr[mid]){
                    end = mid-1;
                }
                else start = mid+1;
            }
        }
        return -1;
    }
};