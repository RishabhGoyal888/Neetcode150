#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(); // Get the size of the input array
        unordered_map<int, int> mpp; // Initialize unordered_map to store prefix sums
        int sum = 0; // Initialize sum to count odd numbers
        int ans = 0; // Initialize answer to count subarrays with exactly 'k' odd numbers
        mpp[0] = 1; // Initialize map with 0 sum to handle cases where subarray starts from index 0

        for (int i = 0; i < n; ++i) { // Iterate through the array
            if (nums[i] % 2 == 1) { // Check if the current number is odd
                sum += 1; // Increment the sum if the number is odd
            }
            int diff = sum - k; // Calculate the difference needed to form a subarray with 'k' odd numbers
            ans += mpp[diff]; // Add the count of subarrays found with the required difference
            mpp[sum]++; // Update the map with the current sum
        }
        return ans; // Return the total count of subarrays with exactly 'k' odd numbers
    }
};