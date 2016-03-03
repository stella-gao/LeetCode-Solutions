// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            int ans = 0, gap = INT_MAX;
            sort(num.begin(), num.end());
            
            for(auto a = num.begin(); a != prev(num.end(), 2); a++) {
                auto b = next(a);
                auto c = prev(num.end());

                while(b < c) {
                    const int sum = *a + *b + *c;
                    if(sum < target)  ++b;
                    else              --c;
                    if(gap > abs(target - sum)) {
                        gap = abs(target - sum);
                        ans = sum;
                    }
                }
            }
            return ans;
        }
};


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        for(int i=0; i<nums.size(); ++i){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l = i+1, r = nums.size()-1;
            while(l<r){
                if(l>i+1 && nums[l]==nums[l-1]){
                    l++;
                    continue;
                }
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==target) return target;
                else if(sum<target) l++;
                else r--;
                if(abs(ans-target)>abs(sum-target))
                    ans = sum;
            }
        }
        return ans;
    }
};
