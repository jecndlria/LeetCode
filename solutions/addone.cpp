/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Runtime: O(n), since we make one pass through the array.
Space: O(n) I think? Not sure, since you can allocate a new array, but it depends on what pushback does considering that worst case scenario for push back is allocation of an entirely new array.

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // This algorithim mirrors classic elementary school row addition, so we start at the last
        // element of the array, or the one's place.
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            // If the current digit is less than 9, no need to carry, just increment and return.
            if (digits[i] < 9) 
            {
                digits[i]++;
                return digits;
            }
            // If it is 9, we set it to 0 (so its technically 10), and we "carry"
            // But since we are only adding one, the carry kind of takes care of itself, so
            // we don't need to do anything special.
            else if (digits[i] == 9)
            {
                digits[i] = 0;
            }
        }
        // After the loop, we need to check if we have an extra place,
        // i.e, we carry beyond the size of the array.
        // The only time we would need an extra place is if the entire array was 9.
        // If the entire array was nine, the loop above makes them all zeros.
        // All we need to do now is set the front to one, and add a 0 to the back, and we're done.
        if (digits[0] == 0)
        {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};