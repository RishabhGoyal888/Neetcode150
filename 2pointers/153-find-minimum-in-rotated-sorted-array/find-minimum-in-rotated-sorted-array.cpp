class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int start=0;
        int end=n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            int left = arr[(mid + n- 1)%n];  //for taking care of boundary cases, added mod
            int right = arr[(mid + 1)%n];
            
            if(arr[mid] <= left && arr[mid] <= right){  //this is the minimum element
                return arr[mid];
            }
            //answer will lie in the unsorted half as minimum element is the pivot for rotating
            //so discarding the sorted half
            else if(arr[mid] <= arr[end]){  //first checking second half, because if both halves will be sorted, means array already sorted, then answer will be in first half.
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }
};