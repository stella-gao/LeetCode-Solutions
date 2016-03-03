/* Two Sum II - Input array is sorted

Problem Description: Given an array of integers that is already sorted in ascending order, 
find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (true) {
            if (numbers[l] + numbers[r] == target)  return {l + 1, r + 1};
            if (numbers[l] + numbers[r] > target)   r--;
            else l++;
        }
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while(l<r){
            if(numbers[l]+numbers[r] == target){
                vector<int> ret;
                ret.push_back(l+1);
                ret.push_back(r+1);
                return ret;
            }else if(numbers[l]+numbers[r] < target){
                l++;
            }else{
                r--;
            }
        }
    }
};
