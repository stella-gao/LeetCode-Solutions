//1.Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices(2, 0);
        unordered_map<int, int> hash; //number, index
        for(int i=0; i<nums.size(); ++i){
            int v = nums[i], u = target-v;
            if(hash.find(u)!=hash.end()){
                indices[0] = hash[u];
                indices[1] = i;
                return indices;
            }else{
                hash[v] = i;
            }
        }
    }
};
