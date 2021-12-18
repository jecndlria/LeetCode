/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
*/

/*
Runtime: O(nlogn + mlogm), where n and m are the sizes of the two input arrays.
This is the runtime because we sort the two arrays then do a linear search through them simultaneously 
(which is ignored in the simplified big O notation)

Memory: Depends on how the sorting algorithm is implemented, could range from 
O(logn + logm) to O(n + m)
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Sort the arrays with the built in sort functions.
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> intersection; 
        
        // Initialize the two pointers we need.
        int nums1CurrentIndex = 0;
        int nums2CurrentIndex = 0;
        
        // Make sure we stop searching when we reach the end of the smaller array.
        // Remember that the array is sorted now.
        while (nums1CurrentIndex < nums1.size() && nums2CurrentIndex < nums2.size())
        {
            // If the element in nums1 is smaller than the current element of nums2, advance only the nums1 pointer since we are sorted.
            if (nums1[nums1CurrentIndex] < nums2[nums2CurrentIndex])
            {
                nums1CurrentIndex++;
            }
            // Same goes for this case, only in reverse.
            else if (nums2[nums2CurrentIndex] < nums1[nums1CurrentIndex])
            {
                nums2CurrentIndex++;
            }
            // If the elements are equal, increment both pointers, then push back the current element (minus one because we just incremented, that would cause us to push back the wrong element/overflow)
            else if (nums1[nums1CurrentIndex++] == nums2[nums2CurrentIndex++])
            {
                intersection.push_back(nums1[nums1CurrentIndex - 1]);
            }
        }
        return intersection;
    }
};