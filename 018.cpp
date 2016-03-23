
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); ++i){
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            for(int j=i+1; j<nums.size(); ++j){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int l = j+1, r = nums.size()-1;
                while(l<r){
                    if(l>j+1 && nums[l]==nums[l-1]){
                        l++; 
                        continue;
                    }
                    if(nums[i]+nums[j]+nums[l]+nums[r]==target){
                        vector<int> vec = {nums[i], nums[j], nums[l], nums[r]};
                        ret.push_back(vec);
                        l++;
                        r--;
                    }
                    else if(nums[i]+nums[j]+nums[l]+nums[r]<target)     l++;
                    else    r--;
                }
            }
        }
        return ret;
    }
};
