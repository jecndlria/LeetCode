/*

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0; // if the array is empty, return immediately.
        
        int uniqueElements = 0;         // goal here is to remove duplicates.
                                        // keeping track of unique elements will help us do that
                                        // this approach iterates through the array,
                                        // finds all the unique elements, moves them to the front,
                                        // then deletes the remainder of the array.
        
        int currentElement = -101;      // initialized to some value that will never be in our input,
                                        // since we are given the constraint that -100 <= nums[i] <= 100.
                                        // guarantees that we will hit the first case of currentElement != nums[i].
        
        for (int i = 0; i < nums.size(); i++) // iterates through the array.
        {
            if (currentElement != nums[i])                  // if the last seen unique element is not equal to the current 
                                                            // (i.e, it is a new unique element):
                
            {
                currentElement = nums[i];                   // change the current element to this new one
                nums[uniqueElements] = currentElement;      // move the new unique element back to the front of the array
                uniqueElements++;                           // increment the amount of unique elements seen
            }
        }
        nums.erase(nums.begin() + uniqueElements, nums.end());     // since the first uniqueElement elements of the array
                                                                   // are the actual unique elements,
                                                                   // we can delete the rest.
        return uniqueElements;
    }
};