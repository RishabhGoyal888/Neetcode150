class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // Ensure nums1 is smaller or equal in size compared to nums2 for minimum time complexity
        if (m < n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        // Calculate the total size of the combined array
        int size = n + m;
        
        // Initialize binary search variables
        int low = 0;
        int high = n;
        int left = (n + m + 1) / 2; // Desired size of the left partition (left half of the combined array)
        
        while (low <= high) {
            // Calculate the partition points for both arrays
            int mid1 = low + (high - low) / 2; // Partition point for nums1, no. of elements in left partition from nums1
            int mid2 = left - mid1; // Partition point for nums2, no. of elements in left partition from nums2
            
            // Initialize variables to store elements surrounding the partition points
            int l1 = INT_MIN; // Smallest element on the left side of nums1
            int l2 = INT_MIN; // Smallest element on the left side of nums2
            int r1 = INT_MAX; // Largest element on the right side of nums1
            int r2 = INT_MAX; // Largest element on the right side of nums2
            
            // Update variables if partition points are within bounds
            if (mid1 < n) r1 = nums1[mid1];
            if (mid2 < m) r2 = nums2[mid2];
            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
            
            // Check if the partition is correct
            if (l1 <= r2 && l2 <= r1) {
                if (size % 2 == 1) return max(l1, l2);
                else return (double)((max(l1, l2) + min(r1, r2)) / 2.0);
            } else if (l1 > r2) {
                high = mid1 - 1; //bcz if we increase no of elements in left part from arr1, next l1 will also be greater than r2, means no. should decrease
            } else {
                low = mid1 + 1;
            }
        }

        return -1;
    }
};