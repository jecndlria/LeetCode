/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

/*
The only O(n) runtime and O(1) memory usage solution this has is to use xor on the array. 
This works because of the following:
Xor any number with 0, and you get that number (a (xor) 0 = a)
Xor any number with itself, and you get 0. 
Therefore, if you xor every single bit of every number in the array, you will get the unique number,
since the numbers that are equal to each other will just become 0.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int useXor = nums[0]; 
        for (int i = 1; i < nums.size(); i++)
        {
            useXor ^= nums[i];
        }
        return useXor;
    }
};