class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);

        int left_base = 1;
        for (int i = 0; i < nums.size(); i++) {
            res[i] *= left_base;
            left_base *= nums[i];
        }

        int right_base = 1;
        for (int j = nums.size() - 1; j >= 0;j--) {
            res[j] *= right_base;
            right_base *= nums[j];
        }

        return res;
    }
};
