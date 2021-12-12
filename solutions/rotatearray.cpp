/* Given an array, rotate the array to the right by k steps, where k is non-negative. */

/* 
REVERSAL ALGORITHM 
First, we have to take care of the case where k > nums.size() because that would put the iterators used out of bounds,
causing errors.
The reason this works is that k reverses where k > nums.size() is redundant since there is only a nums.size() amount of 
unique arrays with rotations of this nature.
So, by taking the modulo of k with the size, we can get the actual rotations we need, and ensure that k is less than
nums.size().
To begin, we first reverse the entire array, since with a rotation, the last element becomes the first.
Then, we rotate from the kth element to the end, since we want the former first element to be adjacent to the last element,
and this step puts the first element where we want it to be.
    It's a good thing to note that, in a rotation, the first element of the array will always be adjacent to the last.
    The only time that this isn't true is if the array is in the initial state it was already in!
Then, we rotate from the beginning of the array to the kth element, putting the last element right next to the first.
*/


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.begin() + k);
    }
};