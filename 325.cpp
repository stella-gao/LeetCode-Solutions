/* Problem: Maximum Size Subarray Sum Equals k

Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time? 
*/

// 96ms
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        vector<int> sums(nums.size()+1, 0);
        unordered_map<int, int> hash;  //sum, index
        hash[0] = 0;
        int ret = 0;
        for(int i=1; i<=nums.size(); ++i){
            sums[i] = sums[i-1]+nums[i-1];
            if(!hash.count(sums[i]))   hash[sums[i]] = i;             // while sum[i] is not in the hash map list...
            int diff = sums[i]-k;
            if(hash.count(diff))       ret = max(ret, i-hash[diff]);  // while diff is in the hash map list...
        }
        return ret;
    }
};
