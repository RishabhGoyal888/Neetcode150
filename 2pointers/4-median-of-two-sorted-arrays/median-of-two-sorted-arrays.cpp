class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int size = n+m;
        if(m < n){
            return findMedianSortedArrays(nums2,nums1);
        }
        int low = 0;
        int high = n;
        int left = (n+m+1)/2;
        while(low<=high){
            int mid1 = low + (high-low)/2;
            int mid2 = left - mid1;
            int minLeft1 = INT_MIN; int minLeft2 = INT_MIN;
            int maxRight1 = INT_MAX; int maxRight2 = INT_MAX;
            if(mid1 < n) maxRight1 = nums1[mid1];
            if(mid2 < m) maxRight2 = nums2[mid2];
            if(mid1 - 1 >=0) minLeft1 = nums1[mid1 - 1];
            if(mid2 - 1 >=0) minLeft2 = nums2[mid2 - 1];
            if(minLeft1 <= maxRight2 && minLeft2 <= maxRight1){
                if(size%2 ==1) return max(minLeft1, minLeft2);
                else return (double)((max(minLeft1,minLeft2) + min(maxRight1,maxRight2))/2.0);
            }
            else if(minLeft1 > maxRight2){
                high = mid1 - 1;
            }
            else{
                low = mid1 + 1;
            }
        }
        return -1;
    }
};