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
            int minLeft1 = INT_MIN; // Smallest element on the left side of nums1
            int minLeft2 = INT_MIN; // Smallest element on the left side of nums2
            int maxRight1 = INT_MAX; // Largest element on the right side of nums1
            int maxRight2 = INT_MAX; // Largest element on the right side of nums2
            
            // Update variables if partition points are within bounds
            if (mid1 < n) maxRight1 = nums1[mid1];
            if (mid2 < m) maxRight2 = nums2[mid2];
            if (mid1 - 1 >= 0) minLeft1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) minLeft2 = nums2[mid2 - 1];
            
            // Check if the partition is correct
            if (minLeft1 <= maxRight2 && minLeft2 <= maxRight1) {
                // If the total size of the combined array is odd, return the maximum element from the left partitions
                if (size % 2 == 1) return max(minLeft1, minLeft2);
                // If the total size of the combined array is even, calculate and return the median
                else return (double)((max(minLeft1, minLeft2) + min(maxRight1, maxRight2)) / 2.0);
            } else if (minLeft1 > maxRight2) {
                // Adjust the search range if the partition is too far to the right
                high = mid1 - 1;
            } else {
                // Adjust the search range if the partition is too far to the left
                low = mid1 + 1;
            }
        }
        
        // Should never reach here
        return -1;
    }
};
