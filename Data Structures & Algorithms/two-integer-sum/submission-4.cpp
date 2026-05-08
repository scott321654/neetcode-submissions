class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indice; // <nums, >

        for (int i = 0; i < nums.size(); i++)
        {
            indice[nums[i]] = i;
        }
        int diff;
        for (int j = 0; j < nums.size(); j++)
        {
            diff = target - nums[j];

            if (indice.count(diff) && j != indice[diff])
                return {j, indice[diff]};
        }

        return {};
    }
};
