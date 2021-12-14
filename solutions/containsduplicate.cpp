/* Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.*/

/*
Runtime: O(n logn)
Memory: O(1)

In order to find duplicates without using extra memory, we must sort the array first, which has
nlogn runtime. 
Since the array is now sorted, we can now iterate through the array, checking adjacent elements for
duplicates and returning early if we find a pair, or returning false if the end is reached.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};