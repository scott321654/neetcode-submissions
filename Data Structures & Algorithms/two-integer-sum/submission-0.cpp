class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]] = i;
        }

        for (int j = 0; j < nums.size(); j++)
        {
            int diff = target - nums[j];
            if (hash.count(diff) && hash[diff] != j) 
            {return {j , hash[diff]};}
        }

        return {};
    }
};
