/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
*/

/*
Runtime: O(n + m), where n and m are the sizes of the two input arrays.
Memory: O(min(n, m)), because we make a hash table using the smaller of the two arrays.
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Swap the arrays to ensure nums1 is smaller to maintain optimal space complexity.
        if (nums1.size() > nums2.size()) { return intersect(nums2, nums1); }
        
        
        // Since keys in an unordered_map must be unique, the keys in the map will be the elements
        // of the array, and the value they will correspond to will be the count.
        unordered_map<int, int> map;
        vector<int> intersection;
        
        // Iterate through the first array, and create a key for each element in the array.
        // If the key already exists, then this will increment the count corresponding to that element.
        // If not, it will create a new element with count 1. 
        for (int i = 0; i < nums1.size(); i++)
        {
            ++map[nums1[i]];                    // Remember: in an unordered map, each key must be unique.
        }
        
        // Now, we iterate through the second array, and check the hash map to find our intersecting elements.
        for (int i = 0; i < nums2.size(); i++)
        {
            // Set the iterator to find the element corresponding to the current element of nums2.
            auto mapIterator = map.find(nums2[i]);
            
            // mapIterator != map.end() will check if the element is actually in the hash table
            // Remember: map.end() is a pointer to the element after the last element in the hash table (null)
            // Remember: C++ evaluates boolean expressions from left to right. If control gets to this
            // point, then the element is in the hash table AND the nums2 array.
            // mapIterator->second is the data value corresponding to the current key, i.e, the count.
            // Decrement it, since we need to make sure that the element in the resulting array 
            // appears exactly as many times as there are intersections.
            // If the count is greater than or equal to 0 (equal to, because we are using the pre-decrement operator)
            // then push it back into the resulting array.
            if (mapIterator != map.end() && --mapIterator->second >= 0)
            {
                intersection.push_back(mapIterator->first);
            }
        }
        return intersection;
    }
    // NOTE: since LeetCode C++ compilers are NOT updated to C++20, the method unordered_map::contains()
    // could not be used, requiring the user of iterators. 
    
    // ANOTHER NOTE: to save even more memory, you could also save the result into one of the existing
    // arrays, but I didn't want to do that as that would be bad practice (overwriting parameters)
};