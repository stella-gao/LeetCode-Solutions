// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            vector<vector<int> > ans;
            if(num.size() < 3)  return ans;
            sort(num.begin(), num.end());

            for(auto a = num.begin(); a < prev(num.end(), 2); ++a) { // prev(num.end()) or prev(num.end(),1) 为最后一个元素，这里a从起始位置一直到倒数第三个位置
                if(a > num.begin() && *a == *(a - 1))  continue; //不考虑下标位置，所以重复的只算一个
                auto b = next(a);
                auto c = prev(num.end());

                while(b < c) {
                    if(b > next(a) && *b == *(b - 1))  ++b;
                    else if(c < prev(num.end()) && *c == *(c + 1))  --c;
                    else {
                        const int sum = *a + *b + *c;
                        if(sum < 0)   ++b;
                        else if(sum > 0)  --c;
                        else {
                            ans.push_back({ *a, *b, *c});
                            ++b;
                            --c;
                        }
                    }
                }
            }
            return ans;
        }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; ++i){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1, r = n-1;
            while(l<r){
                if(l>i+1 && nums[l]==nums[l-1]) {l++; continue;}
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==0){
                    vector<int> vec = {nums[i], nums[l], nums[r]};
                    ret.push_back(vec);
                    l++;
                    r--;
                }else if(sum<0){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ret;
    }
};
