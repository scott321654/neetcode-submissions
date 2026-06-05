class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int left_base = 1, i = 0;
        
        while (i < nums.size()) {
            res[i] = left_base;
            left_base *= nums[i];
            i++;
        }
        
        i = nums.size() - 1;
        int right_base = 1;
        
        while (i >= 0) {
            res[i] *= right_base;
            right_base *= nums[i];
            i--;
        }
        
        return res;
    }
};
