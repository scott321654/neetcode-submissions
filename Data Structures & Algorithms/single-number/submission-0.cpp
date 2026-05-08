class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor_num = 0;

        for (auto& s: nums)
        {
            xor_num ^= s;
        }

        return xor_num;
    }
};
