class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        
        int i = nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        
        if(i<0){ sort(nums.begin(), nums.end());   return; }
 
        int j = nums.size()-1;
        while(j>i && nums[j]<=nums[i]) j--;
        
        swap(nums[i], nums[j]);
        sort(nums.begin()+i+1, nums.end());
    }
};
