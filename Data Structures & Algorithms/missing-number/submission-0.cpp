class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor_num = 0;
        for (int i = 0; i <= nums.size(); i++) {
            xor_num ^= i;
            if (i < nums.size())
                xor_num ^= nums[i];
        }       
        return xor_num;
    }
};
