// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)     return 0;
        
        int index = 0; 
        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[index] != nums[i])
            {
                nums[++index] = nums[i];
            }
        }
        
        return index + 1;    
    }
};




